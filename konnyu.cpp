#include <gecode/int.hh>
#include <gecode/search.hh>
#include <gecode/gist.hh>
#include <gecode/minimodel.hh>

#include <iostream>

using namespace Gecode;
using namespace std;

class Konnyu:public IntMinimizeSpace{
protected:
	IntVarArray v;
	IntVarArray csut;
	IntVarArray het;
	IntVar koltseg;
public:
	Konnyu(void):
	v(*this, 8, 0, 99),
	csut(*this,1,  0,1),
	het(*this,1, 0,1),
	koltseg(*this, 0, 9999999)
	{
		IntVar
		v0(v[0]),
		v1(v[1]),
		v2(v[2]),
		v3(v[3]),
		v4(v[4]),
		v5(v[5]),
		v6(v[6]),
		v7(v[7]);
		IntVar d(csut[0]);
		IntVar e(het[0]);
		
		
		IntArgs c(8), a(8), b(8), ke(8); //ezeket NEM fogja változtatni
		IntVarArgs x(8);
		BoolVar l(*this, 0,1);
		
		x[0]=v0;
		x[1]=v1;
		x[2]=v2;
		x[3]=v3;
		x[4]=v4;
		x[5]=v5;
		x[6]=v6;
		x[7]=v7;		
		
		a[0]=1;
		a[1]=1;
		a[2]=1;
		a[3]=1;
		a[4]=0;
		a[5]=0;
		a[6]=0;
		a[7]=0;
		
		
		b[0]=0;
		b[1]=0;
		b[2]=0;
		b[3]=0;
		b[4]=0;
		b[5]=1;
		b[6]=1;
		b[7]=1;

		//itt határozzuk meg a termékek árait, illetve a vásárolni kívánt mennyiségeket
		//                          V ITT LEHET SZERKESZTENI
		c[0]=380; rel(*this, x[0]>=20);
		c[1]=1000; rel(*this, x[1]>=0);
		c[2]=530; rel(*this, x[2]>=0);
		c[3]=330; rel(*this, x[3]>=0);
		c[4]=119; rel(*this, x[4]>=0);
		c[5]=150; rel(*this, x[5]>=0);
		c[6]=650; rel(*this, x[6]>=20);
		c[7]=70; rel(*this, x[7]>=0);
		
		ke[0]=80;
		ke[1]=50;
		ke[2]=130;
		ke[3]=70;
		ke[4]=0;
		ke[5]=50;
		ke[6]=200;
		ke[7]=70;
		
		
		
		
		
		
		
		
		
		
		
		
		
		//logikai megkötés
		rel(*this, x[0], IRT_GQ, 2, eqv(l));
		//boltba járás költségének megkötése
		IntVar f(*this, 0,2);
		rel(*this, f==d+e);
		rel(*this, f, IRT_GQ, 1);
		
		//maga a végösszeg, ez a célfüggvény amit minimalizálni kell
		rel(*this, koltseg==
			c[0]*x[0]+c[1]*x[1]+c[2]*x[2]+c[3]*x[3]
			+c[4]*x[4]+c[5]*x[5]+c[6]*x[6]+c[7]*x[7]	
					
			-d*(ke[1]*x[1]+ke[2]*x[2]+ke[3]*x[3])
			-e*(ke[5]*x[5]+ke[6]*x[6]+ke[7]*x[7])
			-d*l*x[0]*ke[0]
			//  V ITT LEHET SZERKESZTENI
			+d*620
			//  V ITT LEHET SZERKESZTENI
			+e*400
		);
		branch(*this, v, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
		branch(*this, csut, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
		branch(*this, het, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
	}
	Konnyu(Konnyu& sz) : IntMinimizeSpace(sz){
		v.update(*this, sz.v);
		csut.update(*this, sz.csut);
		het.update(*this, sz.het);
		koltseg.update(*this, sz.koltseg);
	}
	virtual Space* copy(void){
		return new Konnyu(*this);
	}
	virtual IntVar cost(void) const{
		return koltseg;
	}
	void print(void) const {
    	cout << v << endl;
    	cout <<"Csü-Vas: "<< csut << endl;
    	cout <<"Hét-Sze: "<< het << endl;
		cout<<"Végösszeg utazással: "<<koltseg<<endl;
	}
};

int main(){
	Konnyu* s = new Konnyu;
	BAB<Konnyu> e(s);
	Gist::bab(s);
	delete s;
	while(Konnyu* z = e.next()){
		z->print(); delete z;
	}
	
	return 0;
}
