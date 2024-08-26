#include "Optimizer.h"
#include "Problem.h"
/*
	Constructor de la clase Optimizer.
	param o: puntero a la clase Objective.
	param p: vector de la imagen.
	param n: tamaño de la imagen.
	param ftol: tolerancia.
	param max_it: numero maximo de iteraciones.
*/
Optimizer::Optimizer(float (*f)(float*,int), void (*df)(float *,float*, int), float* p, int n, float ftol, int max_it) {
    this->p=p;
    this->func=f;
	this->dfunc=df;
    this->n=n;
    this->ftol=ftol;
    this->max_it=max_it;
    this->iter=0;
    this->fret=0;
    this->fp=0;
}

Optimizer::Optimizer(Problem problem, float* p, int n, float ftol, int max_it) {
    this->p=p;
//  this->func=f;
//	this->dfunc=df;
    this->n=n;
    this->ftol=ftol;
    this->max_it=max_it;
    this->iter=0;
    this->fret=0;
    this->fp=0;
	this->problem=problem;
}

/*
	Destructor de la clase Optimizer.
*/
Optimizer::~Optimizer() {
}



/*
	Función que se encarga de procesar el algoritmo minimizando el gradiente conjugado proyectado.
*/
void Optimizer::frprmn() {
	int j=0,its=0;
	float gg=0,gam=0,fp=0,dgg=0;
	float* g,*h,*xi;
	g = new float[n];
	h = new float[n];
	xi = new float[n];

	//fp = (*func)(p,n); // calcula la funcion a minimizar	
	//(*dfunc)(p,xi,n); // calcula el gradiente en xi

	fp = problem.fo(p, problem.Iobs.tamaño_kernel, problem.Iobs.tamaño_imagen, 65536);
	xi = problem.gradiente(p, problem.Iobs.tamaño_kernel, problem.Iobs.tamaño_imagen, problem.Iobs.tamaño_arreglo);

	// asigna a g el valor de - el gradiente
	for (j=0; j<n; j++) { // ojo se cambio el rango de los indices
		g[j] = -xi[j];
		xi[j]=h[j]=g[j];
	}
 	// for principal hasta un maximo de iteraciones
	for (its=1; its<=max_it; its++) { //iterations_limit defined in command line
		this->iter=its;
		// el vector p, fret se actualiza en el linmin
		linmin(xi); // Aqui modificamos p para obtener un minimo en la direccion xi
		
		// si el error es suficientemente bajo, termina
		if (2.0*fabs(fret-fp) <= ftol*(fabs(fret)+fabs(fp)+EPS)) {
			FREEALL
			return;
		}
//------> fp=(*func)(p,n);
//------> (*dfunc)(p,xi,n); // esta funcion asigna en xi el valor del gradiente
		fp = problem.fo(p, problem.Iobs.tamaño_kernel, problem.Iobs.tamaño_imagen, 65536);
		xi = problem.gradiente(p, problem.Iobs.tamaño_kernel, problem.Iobs.tamaño_imagen, problem.Iobs.tamaño_arreglo);

		
		dgg=gg=0.0;
		// parte de la construction de la direccion en que se va a minimizar
		for (j=0; j<n; j++) {
			gg += g[j]*g[j];
			dgg += (xi[j]+g[j])*xi[j];
		}
		// aqui el gradiente se hace 0 entonces estamos en un minimo
		if (gg == 0.0) {
			FREEALL
			return;
		}
		gam=dgg/gg;
		gam= (gam < 0.0) ? 0.0 : gam; // reset automatico de gam
		// parte de la direccion en que se va a minimizar
		for (j=0; j<n; j++) {
			g[j] = -xi[j];
			xi[j]=h[j]=g[j]+gam*h[j];
		}
	}
	cout << "Too many iterations in frprmn%s\n";
	FREEALL
	return;
}

/*
	Función que se encarga de buscar la minima de una función en una direccion.
	param xi: puntero al vector de la direccion (gradiente).
*/
void Optimizer::linmin(float* xi) {
	// recordar copiar en xicom el valor de xi tal como lo hace la funcion
	// pero podria ser motivo para mejorar la performance
	int j=0;
	float xx=0,xmin=0,fx=0,fb=0,fa=0,bx=0,ax=0;
	this->pcom = new float[n];
	this->xicom = new float[n];
	for (j=0; j<n; j++) {
		this->pcom[j] = p[j];
		this->xicom[j] = xi[j];
	}

	ax = 0.0;
	xx = 1.0;
	mnbrak(&ax,&xx,&bx,&fa,&fx,&fb);
	fret = brent(ax,xx,bx,TOL,&xmin);
	for (j = 0; j < n; j++) {
		xi[j] *= xmin;
		p[j] += xi[j];
	}
	delete[] pcom;
	delete[] xicom;
}

/*
	Función que se encarga de buscar el intervalo minimo.
	param ax,bx,cx: extremos del intervalo.
	param fa,fb,fc: valores de la funcion en los extremos del intervalo.
*/
void Optimizer::mnbrak(float* ax, float* bx, float* cx, float* fa, float* fb, float* fc) {
	float ulim=0,u=0,r=0,q=0,fu=0,dum=0;
	*fa = f1dim(*ax);
	*fb = f1dim(*bx);
	if (*fb > *fa) {
		SHFT(dum,*ax,*bx,dum)
    	SHFT(dum,*fb,*fa,dum)
	}
	*cx = (*bx)+GOLD*(*bx-*ax);
	*fc = f1dim(*cx);
	while (*fb > *fc) {
		r = (*bx-*ax)*(*fb-*fc);
		q=(*bx-*cx)*(*fb-*fa);
		u = (*bx)-((*bx-*cx)*q-(*bx-*ax)*r)/(2.0*SIGN(FMAX(fabs(q-r),TINY),q-r));
		ulim = (*bx)+GLIMIT*(*cx-*bx);
		if ((*bx-u)*(u-*cx) > 0.0) {
			fu = f1dim(u);
			if (fu < *fc) {
				*ax=(*bx);
				*bx=u;
				*fa=(*fb);
				*fb=fu;
				return;
			} else if (fu > *fb) {
				*cx=u;
				*fc=fu;
				return;
			}
			u=(*cx)+GOLD*(*cx-*bx);
			fu=f1dim(u);
		} else if ((*cx-u)*(u-ulim) > 0.0) {
			fu=f1dim(u);
			if (fu < *fc) {
				SHFT(*bx,*cx,u,*cx+GOLD*(*cx-*bx))
				SHFT(*fb,*fc,fu,f1dim(u))
			}
		} else if ((u-ulim)*(ulim-*cx) >= 0.0) {
			u=ulim;
			fu=f1dim(u);
		} else {
			u=(*cx)+GOLD*(*cx-*bx);
			fu=f1dim(u);
		}
	SHFT(*ax,*bx,*cx,u);
	SHFT(*fa,*fb,*fc,fu);
	}
}

/*
	Función que se encarga de buscar el minimo de una función en un intervalo.
	param ax,bx,cx: extremos del intervalo.
	param tol: tolerancia.
	param xmin: puntero al minimo.
	return: valor de la función en el minimo.
*/
float Optimizer::brent(float ax, float bx, float cx, float tol, float *xmin){
	int iter=0;
	float a=0,b=0,d=0.0,etemp=0,fu=0,fv=0,fw=0,fx=0,p=0,q=0,r=0,tol1=0,tol2=0,u=0,v=0,w=0,x=0,xm=0;
	float e=0.0;
	a=(ax < cx ? ax : cx);
	b=(ax > cx ? ax : cx);
	x=w=v=bx;
	fw=fv=fx=f1dim(x);
	for (iter=1; iter<=ITMAX; iter++) {
		xm=0.5*(a+b);
		tol2=2.0*(tol1=tol*fabs(x)+ZEPS);
		if (fabs(x-xm) <= (tol2-0.5*(b-a))) {
			*xmin=x;
			return fx;
		}
		if (fabs(e) > tol1){
			r=(x-w)*(fx-fv);
			q=(x-v)*(fx-fw);
			p=(x-v)*q-(x-w)*r;
			q=2.0*(q-r);
			if (q > 0.0){
				p = -p;
			}

			q=fabs(q);
			etemp=e;
			e=d;

			if (fabs(p) >= fabs(0.5*q*etemp) || p <= q*(a-x) || p >= q*(b-x))
				d=CGOLD*(e=(x >= xm ? a-x : b-x));
			else {
				d=p/q;
				u=x+d;
				if (u-a < tol2 || b-u < tol2)
					d=SIGN(tol1,xm-x);
			}
		} else {
			d=CGOLD*(e=(x >= xm ? a-x : b-x));
		}

		u=(fabs(d) >= tol1 ? x+d : x+SIGN(tol1,d));
		fu=f1dim(u);

		if (fu <= fx) {
			if (u >= x){
				a=x;
			} else {
				b=x;
			}

			SHFT(v,w,x,u)
			SHFT(fv,fw,fx,fu)

		} else {
			if (u < x){
				a=u;
			} else {
				b=u;
			}
			
			if (fu <= fw || w == x) {
				v=w;
				w=u;
				fv=fw;
				fw=fu;
			} else if (fu <= fv || v == x || v == w) {
				v=u;
				fv=fu;
			}
		}
	}
	*xmin=x;
  	return fx;
}

/*
	Wrapper de la función f1dim.
	param x: valor inicial.
	return: valor de la función.
*/
float Optimizer::f1dim(float x) {
	int j=0;
	float f=0,*xt=NULL;
	xt = new float[this->n];
	for (j=0; j< this->n; j++) {
		xt[j]=pcom[j]+x*xicom[j];
	}
//-->f = (*func)(xt,this->n); // calcula la funcion a minimizar
	f = problem.fo(p,problem.Iobs.tamaño_kernel, problem.Iobs.tamaño_imagen, problem.Iobs.tamaño_arreglo);
	delete[] xt;
	return f;
}