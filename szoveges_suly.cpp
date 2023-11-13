#include <gecode/int.hh>
#include <gecode/search.hh>
#include <gecode/gist.hh>
#include <gecode/minimodel.hh>

#include <iostream>

using namespace Gecode;
using namespace std;

class Szoveges:public IntMinimizeSpace{
protected:
	IntVarArray v;
	IntVarArray k10;
	IntVarArray k15;
	IntVar koltseg;
	IntVar kivant;
public:
	Szoveges(void):
	v(*this, 20, 0, 99),
	k10(*this, 20, 0, 99),
	k15(*this, 20, 0, 99),
	koltseg(*this, 0, 9999999),
	kivant(*this, 0.0, 9999999.0)
	{
		IntVar
		v0(v[0]),
		v1(v[1]),
		v2(v[2]),
		v3(v[3]),
		v4(v[4]),
		v5(v[5]),
		v6(v[6]),
		v7(v[7]),
		v8(v[8]),
		v9(v[9]),
		v10(v[10]),
		v11(v[11]),
		v12(v[12]),
		v13(v[13]),
		v14(v[14]),
		v15(v[15]),
		v16(v[16]),
		v17(v[17]),
		v18(v[18]),
		v19(v[19]);
		IntVar
		a0(k10[0]),
		a1(k10[1]),
		a2(k10[2]),
		a3(k10[3]),
		a4(k10[4]),
		a5(k10[5]),
		a6(k10[6]),
		a7(k10[7]),
		a8(k10[8]),
		a9(k10[9]),
		a10(k10[10]),
		a11(k10[11]),
		a12(k10[12]),
		a13(k10[13]),
		a14(k10[14]),
		a15(k10[15]),
		a16(k10[16]),
		a17(k10[17]),
		a18(k10[18]),
		a19(k10[19]);
		IntVar
		b0(k15[0]),
		b1(k15[1]),
		b2(k15[2]),
		b3(k15[3]),
		b4(k15[4]),
		b5(k15[5]),
		b6(k15[6]),
		b7(k15[7]),
		b8(k15[8]),
		b9(k15[9]),
		b10(k15[10]),
		b11(k15[11]),
		b12(k15[12]),
		b13(k15[13]),
		b14(k15[14]),
		b15(k15[15]),
		b16(k15[16]),
		b17(k15[17]),
		b18(k15[18]),
		b19(k15[19]);
		
		IntArgs c(20);
		IntArgs w(20), cw(20); //ezeket NEM fogja változtatni
		IntVarArgs x(20), a(20), b(20);
		BoolVarArgs s(*this, 20, 0,1); 
		IntVarArgs h(*this, 20, 0, 9999); //ezeket fogja változtatni
		
		x[0]=v0;
		x[1]=v1;
		x[2]=v2;
		x[3]=v3;
		x[4]=v4;
		x[5]=v5;
		x[6]=v6;
		x[7]=v7;
		x[8]=v8;
		x[9]=v9;
		x[10]=v10;
		x[11]=v11;
		x[12]=v12;
		x[13]=v13;
		x[14]=v14;
		x[15]=v15;
		x[16]=v16;
		x[17]=v17;
		x[18]=v18;
		x[19]=v19;
		
		a[0]=a0;
		a[1]=a1;
		a[2]=a2;
		a[3]=a3;
		a[4]=a4;
		a[5]=a5;
		a[6]=a6;
		a[7]=a7;
		a[8]=a8;
		a[9]=a9;
		a[10]=a10;
		a[11]=a11;
		a[12]=a12;
		a[13]=a13;
		a[14]=a14;
		a[15]=a15;
		a[16]=a16;
		a[17]=a17;
		a[18]=a18;
		a[19]=a19;
		
		b[0]=b0;
		b[1]=b1;
		b[2]=b2;
		b[3]=b3;
		b[4]=b4;
		b[5]=b5;
		b[6]=b6;
		b[7]=b7;
		b[8]=b8;
		b[9]=b9;
		b[10]=b10;
		b[11]=b11;
		b[12]=b12;
		b[13]=b13;
		b[14]=b14;
		b[15]=b15;
		b[16]=b16;
		b[17]=b17;
		b[18]=b18;
		b[19]=b19;

		//itt határozzuk meg a termékek árait, illetve a vásárolni kívánt mennyiségeket
		//                          V ITT LEHET SZERKESZTENI
		c[0]=2000; rel(*this, x[0]>=3);
		c[1]=800; rel(*this, x[1]>=0);
		c[2]=350; rel(*this, x[2]>=0);
		c[3]=350; rel(*this, x[3]>=2);
		c[4]=500; rel(*this, x[4]>=0);
		c[5]=800; rel(*this, x[5]>=5);
		c[6]=1000; rel(*this, x[6]>=1);
		c[7]=500; rel(*this, x[7]>=0);
		c[8]=750; rel(*this, x[8]>=0);
		c[9]=300; rel(*this, x[9]>=2);
		c[10]=280; rel(*this, x[10]>=60);
		c[11]=1000; rel(*this, x[11]>=23);
		c[12]=330; rel(*this, x[12]>=0);
		c[13]=400; rel(*this, x[13]>=0);
		c[14]=2500; rel(*this, x[14]>=8);
		c[15]=800; rel(*this, x[15]>=0);
		c[16]=300; rel(*this, x[16]>=0);
		c[17]=20000; rel(*this, x[17]>=0);
		c[18]=4000; rel(*this, x[18]>=0);
		c[19]=3200; rel(*this, x[19]>=0);
				
		//a termékek súlya, minél alacsonyabb, annál inkább fogja priorizálni
		//                 V ITT LEHET SZERKESZTENI
		w[0] = 1;
		w[1] = 1;
		w[2] = 1;
		w[3] = 1;
		w[4] = 1;
		w[5] = 1;
		w[6] = 1;
		w[7] = 1;
		w[8] = 1;
		w[9] = 1;
		w[10] = 1;
		w[11] = 1;
		w[12] = 1;
		w[13] = 1;
		w[14] = 1;
		w[15] = 1;
		w[16] = 1;
		w[17] = 1;
		w[18] = 1;
		w[19] = 1;
		
		//súlyozott költségek meghatározása
		cw[0] = c[0] * w[0];
		cw[1] = c[1] * w[1];
		cw[2] = c[2] * w[2];
		cw[3] = c[3] * w[3];
		cw[4] = c[4] * w[4];
		cw[5] = c[5] * w[5];
		cw[6] = c[6] * w[6];
		cw[7] = c[7] * w[7];
		cw[8] = c[8] * w[8];
		cw[9] = c[9] * w[9];
		cw[10] = c[10] * w[10];
		cw[11] = c[11] * w[11];
		cw[12] = c[12] * w[12];
		cw[13] = c[13] * w[13];
		cw[14] = c[14] * w[14];
		cw[15] = c[15] * w[15];
		cw[16] = c[16] * w[16];
		cw[17] = c[17] * w[17];
		cw[18] = c[18] * w[18];
		cw[19] = c[19] * w[19];
		
		//itt megadjuk a ragasztható kedvezménykuponokra vonatkozó korlátozásokat
		rel(*this, a[0]<=x[0]); rel(*this, b[0]==0);
		rel(*this, a[1]+b[1]<=x[1]);
		rel(*this, a[2]==0); rel(*this, b[2]==0);
		rel(*this, a[3]+b[3]<=x[3]);
		rel(*this, a[4]+b[4]<=x[4]);
		rel(*this, a[5]<=x[5]); rel(*this, b[5]==0);
		rel(*this, a[6]<=x[6]); rel(*this, b[6]==0);
		rel(*this, a[7]+b[7]<=x[7]);
		rel(*this, a[8]+b[8]<=x[8]);
		rel(*this, a[9]==0); rel(*this, b[9]==0);
		rel(*this, a[10]+b[10]<=x[10]);
		rel(*this, a[11]<=x[11]); rel(*this, b[11]==0);
		rel(*this, a[12]==0); rel(*this, b[12]==0);
		rel(*this, a[13]+b[13]<=x[13]);
		rel(*this, a[14]==0); rel(*this, b[14]==0);
		rel(*this, a[15]+b[15]<=x[15]);
		rel(*this, a[16]==0); rel(*this, b[16]==0);
		rel(*this, a[17]==0); rel(*this, b[17]==0);
		rel(*this, a[18]==0); rel(*this, b[18]==0);
		rel(*this, a[19]==0); rel(*this, b[19]==0);
		
		//nehezebb megkötések:
		IntVarArgs k(*this, 21, 0, 21);//ez a tömb csak azért kellett, mert a Reify-t tartalmazó
		//                               rel metódus nem tud sima számokat feldolgozni
		for(int i=0;i<=20;i++){
			rel(*this, k[i]==i);
		}
		/*rel(*this, k[0] ==  0);
		rel(*this, k[1] ==  1);
		rel(*this, k[2] ==  2);
		rel(*this, k[3] ==  3);
		rel(*this, k[4] ==  4);
		rel(*this, k[6] ==  6);
		rel(*this, k[15] ==  15);
		rel(*this, k[20] ==  20);*/
		rel(*this, k[6], IRT_LQ ,x[2], eqv(s[2]));
		
		rel(*this, k[3], IRT_LQ, x[4], eqv(s[4]));
		rel(*this, a[4], IRT_EQ, k[0], imp(s[4]));
		rel(*this, b[4], IRT_EQ, k[0], imp(s[4]));
		
		BoolVarArgs seged(*this, 2, 0, 1);
		rel(*this, x[6], IRT_GQ, k[4], eqv(seged[0]));
		rel(*this, x[7], IRT_GQ, k[1], eqv(seged[1]));
		IntVarArgs temp(*this, 1, 0, 1);
		rel(*this, temp[0] == seged[0]*seged[1]);	
		rel(*this, temp[0], IRT_EQ, k[1], eqv(s[6]));
		
		rel(*this, x[9], IRT_GQ, k[6], eqv(s[9]));
		
		rel(*this, x[12], IRT_GQ, k[20], eqv(s[12]));
		
		rel(*this, x[15], IRT_GQ, k[3], eqv(s[15]));
		rel(*this, a[15], IRT_EQ, k[0], imp(s[15]));
		rel(*this, b[15], IRT_EQ, k[0], imp(s[15]));
		
		rel(*this, x[16], IRT_GQ, k[15], eqv(s[16]));
		
		rel(*this, x[17]>=h[18]+h[19]);	
		
		
		
		
		
		
		
		//végösszegre vonatkozó korlátozások
		IntVarArgs szelott(*this, 1, 0, 9999999);
		rel(*this, szelott[0]==
			c[0]*x[0]+c[1]*x[1]+c[2]*x[2]+c[3]*x[3]
			+c[4]*x[4]+c[5]*x[5]+c[6]*x[6]+c[7]*x[7]
			+c[8]*x[8]+c[9]*x[9]+c[10]*x[10]+c[11]*x[11]
			+c[12]*x[12]+c[13]*x[13]+c[14]*x[14]+c[15]*x[15]
			+c[16]*x[16]+c[17]*x[17]+c[18]*x[18]+c[19]*x[19]
			-
			(
				0.1*c[0]*a[0]+0.1*c[1]*a[1]+0.1*c[2]*a[2]+0.1*c[3]*a[3]
				+0.1*c[4]*a[4]+0.1*c[5]*a[5]+0.1*c[6]*a[6]+0.1*c[7]*a[7]
				+0.1*c[8]*a[8]+0.1*c[9]*a[9]+0.1*c[10]*a[10]+0.1*c[11]*a[11]
				+0.1*c[12]*a[12]+0.1*c[13]*a[13]+0.1*c[14]*a[14]+0.1*c[15]*a[15]
				+0.1*c[16]*a[16]+0.1*c[17]*a[17]+0.1*c[18]*a[18]+0.1*c[19]*a[19]
			)
			-
			(
				0.15*c[0]*b[0]+0.15*c[1]*b[1]+0.15*c[2]*b[2]+0.15*c[3]*b[3]
				+0.15*c[4]*b[4]+0.15*c[5]*b[5]+0.15*c[6]*b[6]+0.15*c[7]*b[7]
				+0.15*c[8]*b[8]+0.15*c[9]*b[9]+0.15*c[10]*b[10]+0.15*c[11]*b[11]
				+0.15*c[12]*b[12]+0.15*c[13]*b[13]+0.15*c[14]*b[14]+0.15*c[15]*b[15]
				+0.15*c[16]*b[16]+0.15*c[17]*b[17]+0.15*c[18]*b[18]+0.15*c[19]*b[19]
			)
			-s[2]*x[2]*50
			-s[4]*(x[4]/3)*c[4]
			-s[6]*c[7]
			-s[9]*50*x[9]
			-(x[14]/5)*c[14]
			-s[15]*(x[15]/3)*c[15]
			-h[18]*c[18]*(1/4)
			-h[19]*c[19]*(7/32)
		);
		IntVarArgs husz(*this, 1, 0, 20001); BoolVarArgs szallitas(*this, 1,0,1);
		rel(*this, husz[0]==20000);
		rel(*this, szelott[0], IRT_GQ, husz[0], eqv(szallitas[0]));
		
		
		IntVarArgs harminc(*this, 1,0,30001); BoolVarArgs extrakupon(*this, 2,0,1);
		rel(*this, harminc[0]==30000);	
		rel(*this, szelott[0], IRT_GQ, harminc[0], eqv(extrakupon[0]));
		
		//10%-os kuponok száma:
		//         V ITT LEHET SZERKESZTENI
		rel(*this, 12>=	a[0]+a[1]+a[2]+a[3]
						+a[4]+a[5]+a[6]+a[7]
						+a[8]+a[9]+a[10]+a[11]
						+a[12]+a[13]+a[14]+a[15]
						+a[16]+a[17]+a[18]+a[19]
						-s[12]-s[16]-extrakupon[0]);
		
		//15%-os kuponok száma:
		//          V ITT LEHET SZERKESZTENI
		rel(*this, 	7>=b[0]+b[1]+b[2]+b[3]
					+b[4]+b[5]+b[6]+b[7]
					+b[8]+b[9]+b[10]+b[11]
					+b[12]+b[13]+b[14]+b[15]
					+b[16]+b[17]+b[18]+b[19]);
		
		
		//maga a végösszeg, ez a célfüggvény amit minimalizálni kell
		rel(*this, koltseg==
			c[0]*x[0]+c[1]*x[1]+c[2]*x[2]+c[3]*x[3]
			+c[4]*x[4]+c[5]*x[5]+c[6]*x[6]+c[7]*x[7]
			+c[8]*x[8]+c[9]*x[9]+c[10]*x[10]+c[11]*x[11]
			+c[12]*x[12]+c[13]*x[13]+c[14]*x[14]+c[15]*x[15]
			+c[16]*x[16]+c[17]*x[17]+c[18]*x[18]+c[19]*x[19]
			-
			(
				0.1*c[0]*a[0]+0.1*c[1]*a[1]+0.1*c[2]*a[2]+0.1*c[3]*a[3]
				+0.1*c[4]*a[4]+0.1*c[5]*a[5]+0.1*c[6]*a[6]+0.1*c[7]*a[7]
				+0.1*c[8]*a[8]+0.1*c[9]*a[9]+0.1*c[10]*a[10]+0.1*c[11]*a[11]
				+0.1*c[12]*a[12]+0.1*c[13]*a[13]+0.1*c[14]*a[14]+0.1*c[15]*a[15]
				+0.1*c[16]*a[16]+0.1*c[17]*a[17]+0.1*c[18]*a[18]+0.1*c[19]*a[19]
			)
			-
			(
				0.15*c[0]*b[0]+0.15*c[1]*b[1]+0.15*c[2]*b[2]+0.15*c[3]*b[3]
				+0.15*c[4]*b[4]+0.15*c[5]*b[5]+0.15*c[6]*b[6]+0.15*c[7]*b[7]
				+0.15*c[8]*b[8]+0.15*c[9]*b[9]+0.15*c[10]*b[10]+0.15*c[11]*b[11]
				+0.15*c[12]*b[12]+0.15*c[13]*b[13]+0.15*c[14]*b[14]+0.15*c[15]*b[15]
				+0.15*c[16]*b[16]+0.15*c[17]*b[17]+0.15*c[18]*b[18]+0.15*c[19]*b[19]
			)
			-s[2]*x[2]*50
			-s[4]*(x[4]/3)*c[4]
			-s[6]*c[7] //ITT VOLT HIBA
			-s[9]*50*x[9]
			-(x[14]/5)*c[14]
			-s[15]*(x[15]/3)*c[15]
			-h[18]*c[18]*(1/4)
			-h[19]*c[19]*(7/32)
			+1000*(1-szallitas[0])
		);
		
		//a súlyozott költség
		rel(*this, kivant ==
			cw[0]*x[0]+cw[1]*x[1]+cw[2]*x[2]+cw[3]*x[3]
			+cw[4]*x[4]+cw[5]*x[5]+cw[6]*x[6]+cw[7]*x[7]
			+cw[8]*x[8]+cw[9]*x[9]+cw[10]*x[10]+cw[11]*x[11]
			+cw[12]*x[12]+cw[13]*x[13]+cw[14]*x[14]+cw[15]*x[15]
			+cw[16]*x[16]+cw[17]*x[17]+cw[18]*x[18]+cw[19]*x[19]
			-
			(
				0.1*cw[0]*a[0]+0.1*cw[1]*a[1]+0.1*cw[2]*a[2]+0.1*cw[3]*a[3]
				+0.1*cw[4]*a[4]+0.1*cw[5]*a[5]+0.1*cw[6]*a[6]+0.1*cw[7]*a[7]
				+0.1*cw[8]*a[8]+0.1*cw[9]*a[9]+0.1*cw[10]*a[10]+0.1*cw[11]*a[11]
				+0.1*cw[12]*a[12]+0.1*cw[13]*a[13]+0.1*cw[14]*a[14]+0.1*cw[15]*a[15]
				+0.1*cw[16]*a[16]+0.1*cw[17]*a[17]+0.1*cw[18]*a[18]+0.1*cw[19]*a[19]
			)
			-
			(
				0.15*cw[0]*b[0]+0.15*cw[1]*b[1]+0.15*cw[2]*b[2]+0.15*cw[3]*b[3]
				+0.15*cw[4]*b[4]+0.15*cw[5]*b[5]+0.15*cw[6]*b[6]+0.15*cw[7]*b[7]
				+0.15*cw[8]*b[8]+0.15*cw[9]*b[9]+0.15*cw[10]*b[10]+0.15*cw[11]*b[11]
				+0.15*cw[12]*b[12]+0.15*cw[13]*b[13]+0.15*cw[14]*b[14]+0.15*cw[15]*b[15]
				+0.15*cw[16]*b[16]+0.15*cw[17]*b[17]+0.15*cw[18]*b[18]+0.15*cw[19]*b[19]
			)
			-s[2]*x[2]*(cw[2]*(1/7))
			-s[4]*(x[4]/3)*cw[4]
			-s[6]*cw[7]
			-s[9]*(cw[9]*(1/6))*x[9]
			-(x[14]/5)*cw[14]
			-s[15]*(x[15]/3)*cw[15]
			-h[18]*cw[18]*(1/4)
			-h[19]*cw[19]*(7/32)
			+1000*(1-szallitas[0])
		);
		
		branch(*this, v, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
		branch(*this, k10, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
		branch(*this, k15, INT_VAR_SIZE_MIN(), INT_VAL_MIN());
	}
	Szoveges(Szoveges& sz) : IntMinimizeSpace(sz){
		v.update(*this, sz.v);
		k10.update(*this, sz.k10);
		k15.update(*this, sz.k15);
		koltseg.update(*this, sz.koltseg);
	}
	virtual Space* copy(void){
		return new Szoveges(*this);
	}
	virtual IntVar cost(void) const{
		return koltseg;
	}
	void print(void) const {
    	cout << v << endl;
    	cout << k10 << endl;
    	cout << k15 << endl;
		cout<<koltseg<<endl;
		//cout<<szelott<<endl;
	}
};

int main(){
	Szoveges* s = new Szoveges;
	BAB<Szoveges> e(s);
	Gist::bab(s);
	delete s;
	while(Szoveges* z = e.next()){
		z->print(); delete z;
	}
	
	return 0;
}
