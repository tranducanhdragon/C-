#include <iostream>
using namespace std;

const string donvi[11] = { "khong ","mot ","hai ","ba ","bon ","nam ","sau ", "bay ", "tam ","chin ","muoi " };
const string thapphan[9] = {"phay mot ","phay hai ","phay ba ","phay bon ","phay nam ","phay sau ","phay bay ","phay tam ","phay chin "};


void DonVi(float &n){
	int so = (int)n;
	switch(so){
    	case 0:{
    		cout<<donvi[so];
			break;
		}
    	case 1:{
    		cout<<donvi[so];
			break;
		}
		case 2:{
			cout<<donvi[so];
			break;
		}
		case 3:{
			cout<<donvi[so];
			break;
		}
		case 4:{
			cout<<donvi[so];
			break;
		}
		case 5:{
			cout<<donvi[so];
			break;
		}
		case 6:{
			cout<<donvi[so];
			break;
		}
		case 7:{
			cout<<donvi[so];
			break;
		}
		case 8:{
			cout<<donvi[so];
			break;
		}
		case 9:{
			cout<<donvi[so];
			break;
		}
		case 10:{
			cout<<donvi[so];
			break;
		}
	}
}
void ThapPhan(float &n){
	
	int c = n/1;
//	cout<<c;
	float t = n - c;

	float k = t*10;
//	cout<<t*10;
//	cout<<k;
	c = (int)(k+0.5);
//	cout<<c;
		switch(c){
    	    
    	    case 1:{
    		    cout<<thapphan[c-1];
			    break;
		    }
		    case 2:{
			    cout<<thapphan[c-1];
			    break;
		    }
		    case 3:{
			    cout<<thapphan[c-1];
			    break;
		    }
		    case 4:{
			    cout<<thapphan[c-1];
			    break;
		    }
		    case 5:{
			    cout<<thapphan[c-1];
			    break;
		    }
		    case 6:{
			    cout<<thapphan[c-1];
			    break;
		    }
		    case 7:{
			    cout<<thapphan[c-1];
			    break;
		    }
		    case 8:{
			    cout<<thapphan[c-1];
			    break;
		    }
		    case 9:{
		    	cout<<thapphan[c-1];
				break;
			}
	    }
	
}
int main(){
	
    float n = 0;
	cin>>n;
    DonVi(n);
    ThapPhan(n);
    
    return 0;
}
