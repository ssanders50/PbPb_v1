

  if(replay==N112ASUB2||replay==N112ASUB3) {
    hdenom = GetVNPt(N2SUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2, resAdenom,resBdenom, vintdenom,vintedenom, false);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hpt    = GetVNPt(N112ASUB3, bin, EtaMin,EtaMax, hA, hB, nwspec, resA, resB, vint,vinte, false);
    if(hpt==NULL) return;
    double res = (resAdenom[0]+resBdenom[0])/2.;
      for(int i = 0; i<hpt->GetN(); i++) {
         double ef = hpt->GetEY()[i]/hpt->GetY()[i];
         hpt->GetY()[i]/=res;
         hpt->GetEY()[i]/=res;
      
         ef = hA->GetEY()[i]/hA->GetY()[i];
         hA->GetY()[i]/=resBdenom[0];
         hA->GetEY()[i]/=resBdenom[0];
      
         ef = hB->GetEY()[i]/hB->GetY()[i];
         hB->GetY()[i]/=resAdenom[0];
         hB->GetEY()[i]/=resAdenom[0];
       }
   
  } else if (replay==N123ASUB2||replay==N123ASUB3){
    hdenom = GetVNPt(N3SUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2, resAdenom,resBdenom,vintdenom,vintedenom, false);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hpt    = GetVNPt(N123ASUB3, bin, EtaMin,EtaMax, hA, hB, nwspec, resA, resB, vint,vinte, false);
    if(hpt==NULL) return;
    double res = (resAdenom[0]+resBdenom[0])/2.;
    for(int i = 0; i<hpt->GetN(); i++) {
       double ef = hpt->GetEY()[i]/hpt->GetY()[i];
       hpt->GetY()[i]/=res;
       hpt->GetEY()[i]/=res;
      
       ef = hA->GetEY()[i]/hA->GetY()[i];
       hA->GetY()[i]/=resBdenom[0];
       hA->GetEY()[i]/=resBdenom[0];
      
       ef = hB->GetEY()[i]/hB->GetY()[i];
       hB->GetY()[i]/=resAdenom[0];
       hB->GetEY()[i]/=resAdenom[0];
     }
    
  } else if (replay==N42ASUB2||replay==N42ASUB3){
    cout<<"cneter"<<endl;
    hdenom = GetVNPt(N42SUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2, resAdenom,resBdenom,vintdenom,vintedenom, false);
    cout<<"hdenom: "<<hdenom<<endl;
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hpt    = GetVNPt(N42ASUB3, bin, EtaMin,EtaMax, hA, hB, nwspec, resA, resB, vint,vinte, true);
    double res = (resAdenom[0]+resBdenom[0])/2.;
    for(int i = 0; i<hpt->GetN(); i++) {
       double ef = hpt->GetEY()[i]/hpt->GetY()[i];
       hpt->GetY()[i]/=res;
       hpt->GetEY()[i]/=res;
      
       ef = hA->GetEY()[i]/hA->GetY()[i];
       hA->GetY()[i]/=resBdenom[0];
       hA->GetEY()[i]/=resBdenom[0];
      
       ef = hB->GetEY()[i]/hB->GetY()[i];
       hB->GetY()[i]/=resAdenom[0];
       hB->GetEY()[i]/=resAdenom[0];
     }
  } else if (replay==D24ASUB2||replay==D24ASUB3){
    hdenom = GetVNPt(D24SUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2, resAdenom,resBdenom,vintdenom,vintedenom, false);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hpt    = GetVNPt(D24ASUB3, bin, EtaMin,EtaMax, hA, hB, nwspec, resA, resB, vint,vinte, true);
    double res = (resAdenom[0]+resBdenom[0])/2.;
    for(int i = 0; i<hpt->GetN(); i++) {
       double ef = hpt->GetEY()[i]/hpt->GetY()[i];
       hpt->GetY()[i]/=res;
       hpt->GetEY()[i]/=res;
      
       ef = hA->GetEY()[i]/hA->GetY()[i];
       hA->GetY()[i]/=resBdenom[0];
       hA->GetEY()[i]/=resBdenom[0];
      
       ef = hB->GetEY()[i]/hB->GetY()[i];
       hB->GetY()[i]/=resAdenom[0];
       hB->GetEY()[i]/=resAdenom[0];
     }
    
  } else if (replay==N62ASUB2||replay==N62ASUB3){
    hdenom = GetVNPt(N62SUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2, resAdenom,resBdenom,vintdenom,vintedenom, false);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hpt    = GetVNPt(N62ASUB3, bin, EtaMin,EtaMax, hA, hB, nwspec, resA, resB, vint,vinte, true);
    double res = (resAdenom[0]+resBdenom[0])/2.;
    for(int i = 0; i<hpt->GetN(); i++) {
       double ef = hpt->GetEY()[i]/hpt->GetY()[i];
       hpt->GetY()[i]/=res;
       hpt->GetEY()[i]/=res;
      
       ef = hA->GetEY()[i]/hA->GetY()[i];
       hA->GetY()[i]/=resBdenom[0];
       hA->GetEY()[i]/=resBdenom[0];
      
       ef = hB->GetEY()[i]/hB->GetY()[i];
       hB->GetY()[i]/=resAdenom[0];
       hB->GetEY()[i]/=resAdenom[0];
     }
  } else if (replay==D26ASUB2||replay==D26ASUB3){
    hdenom = GetVNPt(D26SUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2, resAdenom,resBdenom,vintdenom,vintedenom, false);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hpt    = GetVNPt(D26ASUB3, bin, EtaMin,EtaMax, hA, hB, nwspec, resA, resB, vint,vinte, true);
    double res = (resAdenom[0]+resBdenom[0])/2.;
    for(int i = 0; i<hpt->GetN(); i++) {
       double ef = hpt->GetEY()[i]/hpt->GetY()[i];
       hpt->GetY()[i]/=res;
       hpt->GetEY()[i]/=res;
      
       ef = hA->GetEY()[i]/hA->GetY()[i];
       hA->GetY()[i]/=resBdenom[0];
       hA->GetEY()[i]/=resBdenom[0];
      
       ef = hB->GetEY()[i]/hB->GetY()[i];
       hB->GetY()[i]/=resAdenom[0];
       hB->GetEY()[i]/=resAdenom[0];
     }
  } else if (replay==N63ASUB3||replay==N63ASUB3){
    hdenom = GetVNPt(N63SUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2, resAdenom,resBdenom,vintdenom,vintedenom, false);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hpt    = GetVNPt(N63ASUB3, bin, EtaMin,EtaMax, hA, hB, nwspec, resA, resB, vint,vinte, true);
    double res = (resAdenom[0]+resBdenom[0])/2.;
    for(int i = 0; i<hpt->GetN(); i++) {
       double ef = hpt->GetEY()[i]/hpt->GetY()[i];
       hpt->GetY()[i]/=res;
       hpt->GetEY()[i]/=res;
      
       ef = hA->GetEY()[i]/hA->GetY()[i];
       hA->GetY()[i]/=resBdenom[0];
       hA->GetEY()[i]/=resBdenom[0];
      
       ef = hB->GetEY()[i]/hB->GetY()[i];
       hB->GetY()[i]/=resAdenom[0];
       hB->GetEY()[i]/=resAdenom[0];
     }
  } else if (replay==D34ASUB2||replay==D34ASUB3){
    hdenom = GetVNPt(D34SUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2, resAdenom,resBdenom,vintdenom,vintedenom, false);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hpt    = GetVNPt(D34ASUB3, bin, EtaMin,EtaMax, hA, hB, nwspec, resA, resB, vint,vinte, true);
    double res = (resAdenom[0]+resBdenom[0])/2.;
    for(int i = 0; i<hpt->GetN(); i++) {
       double ef = hpt->GetEY()[i]/hpt->GetY()[i];
       hpt->GetY()[i]/=res;
       hpt->GetEY()[i]/=res;
      
       ef = hA->GetEY()[i]/hA->GetY()[i];
       hA->GetY()[i]/=resBdenom[0];
       hA->GetEY()[i]/=resBdenom[0];
      
       ef = hB->GetEY()[i]/hB->GetY()[i];
       hB->GetY()[i]/=resAdenom[0];
       hB->GetEY()[i]/=resAdenom[0];
     }
    
    
  } else if(chi4) {
    hdenom = GetVNPt(D24SUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2, resAdenom, resBdenom, vintdenom,vintedenom, true);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hpt    = GetVNPt(N42SUB3, bin, EtaMin,EtaMax, hA, hB, nwspec,resA,resB,  vint,vinte, true);
    vint/=vintdenom;
    vinte/=vintdenom;
    if(!NumOnly && !DenomOnly) { 
      for(int i = 0; i<hpt->GetN(); i++) {
    	double ef = hpt->GetEY()[i]/hpt->GetY()[i];
    	hpt->GetY()[i]/=hdenom->GetY()[i];
    	hpt->GetEY()[i]=hpt->GetY()[i]*sqrt(ef*ef+pow(hdenom->GetEY()[i]/hdenom->GetY()[i],2));
	
    	ef = hA->GetEY()[i]/hA->GetY()[i];
    	hA->GetY()[i]/=hAdenom->GetY()[i];
    	hA->GetEY()[i]=hA->GetY()[i]*sqrt(ef*ef+pow(hAdenom->GetEY()[i]/hAdenom->GetY()[i],2));
	
    	ef = hB->GetEY()[i]/hB->GetY()[i];
    	hB->GetY()[i]/=hBdenom->GetY()[i];
    	hB->GetEY()[i]=hB->GetY()[i]*sqrt(ef*ef+pow(hBdenom->GetEY()[i]/hBdenom->GetY()[i],2));
      }
    }
  } else if(replay==CHI4A) {
    hdenom = GetVNPt(D24ASUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2, resAdenom, resBdenom, vintdenom,vintedenom, true);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hpt    = GetVNPt(N42ASUB3, bin, EtaMin,EtaMax, hA, hB, nwspec,resA,resB,  vint,vinte, true);
    vint/=vintdenom;
    vinte/=vintdenom;
    if(!NumOnly && !DenomOnly) { 
      for(int i = 0; i<hpt->GetN(); i++) {
    	double ef = hpt->GetEY()[i]/hpt->GetY()[i];
    	hpt->GetY()[i]/=hdenom->GetY()[i];
    	hpt->GetEY()[i]=hpt->GetY()[i]*sqrt(ef*ef+pow(hdenom->GetEY()[i]/hdenom->GetY()[i],2));
	
    	ef = hA->GetEY()[i]/hA->GetY()[i];
    	hA->GetY()[i]/=hAdenom->GetY()[i];
    	hA->GetEY()[i]=hA->GetY()[i]*sqrt(ef*ef+pow(hAdenom->GetEY()[i]/hAdenom->GetY()[i],2));
	
    	ef = hB->GetEY()[i]/hB->GetY()[i];
    	hB->GetY()[i]/=hBdenom->GetY()[i];
    	hB->GetEY()[i]=hB->GetY()[i]*sqrt(ef*ef+pow(hBdenom->GetEY()[i]/hBdenom->GetY()[i],2));
      }
    }
  } else if(chi5) {
    hdenom = GetVNPt(D2232SUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom, nwspec2, resAdenom, resBdenom,vintdenom,vintedenom, true);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hpt = GetVNPt(N523SUB3, bin, EtaMin,EtaMax, hA, hB,nwspec,resA,resB, vint,vinte, true);
    vint/=vintdenom;
    vinte/=vintdenom;
    if(DenomOnly) {
      hA=hAdenom;
      hB=hBdenom;
      hpt=hdenom;
    }
    if(!NumOnly && !DenomOnly) {
      for(int i = 0; i<hpt->GetN(); i++) {
	double ef = hpt->GetEY()[i]/hpt->GetY()[i];
	hpt->GetY()[i]/=hdenom->GetY()[i];
	hpt->GetEY()[i]=hpt->GetY()[i]*sqrt(ef*ef+pow(hdenom->GetEY()[i]/hdenom->GetY()[i],2));
	
	ef = hA->GetEY()[i]/hA->GetY()[i];
	hA->GetY()[i]/=hAdenom->GetY()[i];
	hA->GetEY()[i]=hA->GetY()[i]*sqrt(ef*ef+pow(hAdenom->GetEY()[i]/hAdenom->GetY()[i],2));
	
      ef = hB->GetEY()[i]/hB->GetY()[i];
      hB->GetY()[i]/=hBdenom->GetY()[i];
      hB->GetEY()[i]=hB->GetY()[i]*sqrt(ef*ef+pow(hBdenom->GetEY()[i]/hBdenom->GetY()[i],2));
      }
    }
  } else if(replay==CHI5A) {
    hdenom = GetVNPt(D2232ASUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom, nwspec2, resAdenom, resBdenom,vintdenom,vintedenom, true);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hpt = GetVNPt(N523ASUB3, bin, EtaMin,EtaMax, hA, hB,nwspec,resA,resB, vint,vinte, true);
    vint/=vintdenom;
    vinte/=vintdenom;
    if(DenomOnly) {
      hA=hAdenom;
      hB=hBdenom;
      hpt=hdenom;
    }
    if(!NumOnly && !DenomOnly) {
      for(int i = 0; i<hpt->GetN(); i++) {
	double ef = hpt->GetEY()[i]/hpt->GetY()[i];
	hpt->GetY()[i]/=hdenom->GetY()[i];
	hpt->GetEY()[i]=hpt->GetY()[i]*sqrt(ef*ef+pow(hdenom->GetEY()[i]/hdenom->GetY()[i],2));
	
	ef = hA->GetEY()[i]/hA->GetY()[i];
	hA->GetY()[i]/=hAdenom->GetY()[i];
	hA->GetEY()[i]=hA->GetY()[i]*sqrt(ef*ef+pow(hAdenom->GetEY()[i]/hAdenom->GetY()[i],2));
	
      ef = hB->GetEY()[i]/hB->GetY()[i];
      hB->GetY()[i]/=hBdenom->GetY()[i];
      hB->GetEY()[i]=hB->GetY()[i]*sqrt(ef*ef+pow(hBdenom->GetEY()[i]/hBdenom->GetY()[i],2));
      }
    }
  } else if(chi62) {
    hpt = GetVNPt(N62SUB3, bin, EtaMin,EtaMax, hA, hB,nwspec, resA,resB, vint,vinte, true);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hdenom = GetVNPt(D26SUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2,resAdenom,resBdenom, vintdenom,vintedenom, true);
    vint/=vintdenom;
    vinte/=vintdenom;
    for(int i = 0; i<hpt->GetN(); i++) {
      double ef = hpt->GetEY()[i]/hpt->GetY()[i];
      hpt->GetY()[i]/=hdenom->GetY()[i];
      hpt->GetEY()[i]=hpt->GetY()[i]*sqrt(ef*ef+pow(hdenom->GetEY()[i]/hdenom->GetY()[i],2));
      
      ef = hA->GetEY()[i]/hA->GetY()[i];
      hA->GetY()[i]/=hAdenom->GetY()[i];
      hA->GetEY()[i]=hA->GetY()[i]*sqrt(ef*ef+pow(hAdenom->GetEY()[i]/hAdenom->GetY()[i],2));
      
      ef = hB->GetEY()[i]/hB->GetY()[i];
      hB->GetY()[i]/=hBdenom->GetY()[i];
      hB->GetEY()[i]=hB->GetY()[i]*sqrt(ef*ef+pow(hBdenom->GetEY()[i]/hBdenom->GetY()[i],2));
    }
  } else if(replay==CHI62A) {
    hpt = GetVNPt(N62ASUB3, bin, EtaMin,EtaMax, hA, hB,nwspec, resA,resB, vint,vinte, true);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hdenom = GetVNPt(D26ASUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2,resAdenom,resBdenom, vintdenom,vintedenom, true);
    vint/=vintdenom;
    vinte/=vintdenom;
    for(int i = 0; i<hpt->GetN(); i++) {
      double ef = hpt->GetEY()[i]/hpt->GetY()[i];
      hpt->GetY()[i]/=hdenom->GetY()[i];
      hpt->GetEY()[i]=hpt->GetY()[i]*sqrt(ef*ef+pow(hdenom->GetEY()[i]/hdenom->GetY()[i],2));
      
      ef = hA->GetEY()[i]/hA->GetY()[i];
      hA->GetY()[i]/=hAdenom->GetY()[i];
      hA->GetEY()[i]=hA->GetY()[i]*sqrt(ef*ef+pow(hAdenom->GetEY()[i]/hAdenom->GetY()[i],2));
      
      ef = hB->GetEY()[i]/hB->GetY()[i];
      hB->GetY()[i]/=hBdenom->GetY()[i];
      hB->GetEY()[i]=hB->GetY()[i]*sqrt(ef*ef+pow(hBdenom->GetEY()[i]/hBdenom->GetY()[i],2));
    }
  } else if(chi63) {
    hpt = GetVNPt(N63SUB3, bin, EtaMin,EtaMax, hA, hB,nwspec, resA, resB,vint,vinte, true);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hdenom = GetVNPt(D34SUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2, resAdenom,resBdenom, vintdenom,vintedenom, true);
    vint/=vintdenom;
    vinte/=vintdenom;
    for(int i = 0; i<hpt->GetN(); i++) {
      double ef = hpt->GetEY()[i]/hpt->GetY()[i];
      hpt->GetY()[i]/=hdenom->GetY()[i];
      hpt->GetEY()[i]=hpt->GetY()[i]*sqrt(ef*ef+pow(hdenom->GetEY()[i]/hdenom->GetY()[i],2));
      
      ef = hA->GetEY()[i]/hA->GetY()[i];
      hA->GetY()[i]/=hAdenom->GetY()[i];
      hA->GetEY()[i]=hA->GetY()[i]*sqrt(ef*ef+pow(hAdenom->GetEY()[i]/hAdenom->GetY()[i],2));
      
      ef = hB->GetEY()[i]/hB->GetY()[i];
      hB->GetY()[i]/=hBdenom->GetY()[i];
      hB->GetEY()[i]=hB->GetY()[i]*sqrt(ef*ef+pow(hBdenom->GetEY()[i]/hBdenom->GetY()[i],2));
    }
  } else if(replay==CHI63A) {
    hpt = GetVNPt(N63ASUB3, bin, EtaMin,EtaMax, hA, hB,nwspec, resA, resB,vint,vinte, true);
    fin->Close();
    if(hdenom==NULL) return;
    cout<<"rootFile: "<<rootFile.data()<<endl;

    fin = new TFile(rootFile.data(),"r");
    hdenom = GetVNPt(D34ASUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2, resAdenom,resBdenom, vintdenom,vintedenom, true);
    vint/=vintdenom;
    vinte/=vintdenom;
    for(int i = 0; i<hpt->GetN(); i++) {
      double ef = hpt->GetEY()[i]/hpt->GetY()[i];
      hpt->GetY()[i]/=hdenom->GetY()[i];
      hpt->GetEY()[i]=hpt->GetY()[i]*sqrt(ef*ef+pow(hdenom->GetEY()[i]/hdenom->GetY()[i],2));
      
      ef = hA->GetEY()[i]/hA->GetY()[i];
      hA->GetY()[i]/=hAdenom->GetY()[i];
      hA->GetEY()[i]=hA->GetY()[i]*sqrt(ef*ef+pow(hAdenom->GetEY()[i]/hAdenom->GetY()[i],2));
      
      ef = hB->GetEY()[i]/hB->GetY()[i];
      hB->GetY()[i]/=hBdenom->GetY()[i];
      hB->GetEY()[i]=hB->GetY()[i]*sqrt(ef*ef+pow(hBdenom->GetEY()[i]/hBdenom->GetY()[i],2));
    }
  } else if(chi7) {
    hpt = GetVNPt(N723SUB3, bin, EtaMin,EtaMax, hA, hB,nwspec, resA,resB, vint,vinte,true);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hdenom = GetVNPt(D2432SUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2,resAdenom,resBdenom, vintdenom,vintedenom, true);
    vint/=vintdenom;
    vinte/=vintdenom;
    for(int i = 0; i<hpt->GetN(); i++) {
      double ef = hpt->GetEY()[i]/hpt->GetY()[i];
      hpt->GetY()[i]/=hdenom->GetY()[i];
      hpt->GetEY()[i]=hpt->GetY()[i]*sqrt(ef*ef+pow(hdenom->GetEY()[i]/hdenom->GetY()[i],2));
      
      ef = hA->GetEY()[i]/hA->GetY()[i];
      hA->GetY()[i]/=hAdenom->GetY()[i];
      hA->GetEY()[i]=hA->GetY()[i]*sqrt(ef*ef+pow(hAdenom->GetEY()[i]/hAdenom->GetY()[i],2));
      
      ef = hB->GetEY()[i]/hB->GetY()[i];
      hB->GetY()[i]/=hBdenom->GetY()[i];
      hB->GetEY()[i]=hB->GetY()[i]*sqrt(ef*ef+pow(hBdenom->GetEY()[i]/hBdenom->GetY()[i],2));
    }
  } else if(replay==CHI7A) {
    hpt = GetVNPt(N723ASUB3, bin, EtaMin,EtaMax, hA, hB,nwspec, resA,resB, vint,vinte,true);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hdenom = GetVNPt(D2432ASUB3, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2,resAdenom,resBdenom, vintdenom,vintedenom, true);
    vint/=vintdenom;
    vinte/=vintdenom;
    for(int i = 0; i<hpt->GetN(); i++) {
      double ef = hpt->GetEY()[i]/hpt->GetY()[i];
      hpt->GetY()[i]/=hdenom->GetY()[i];
      hpt->GetEY()[i]=hpt->GetY()[i]*sqrt(ef*ef+pow(hdenom->GetEY()[i]/hdenom->GetY()[i],2));
      
      ef = hA->GetEY()[i]/hA->GetY()[i];
      hA->GetY()[i]/=hAdenom->GetY()[i];
      hA->GetEY()[i]=hA->GetY()[i]*sqrt(ef*ef+pow(hAdenom->GetEY()[i]/hAdenom->GetY()[i],2));
      
      ef = hB->GetEY()[i]/hB->GetY()[i];
      hB->GetY()[i]/=hBdenom->GetY()[i];
      hB->GetEY()[i]=hB->GetY()[i]*sqrt(ef*ef+pow(hBdenom->GetEY()[i]/hBdenom->GetY()[i],2));
    }
  } else if(chi7eff) {
    hpt = GetVNPt(N723EFF, bin, EtaMin,EtaMax, hA, hB, nwspec,resA, resB, vint,vinte,true);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hdenom = GetVNPt(D2432EFF, bin, EtaMin,EtaMax, hAdenom, hBdenom, nwspec2,resAdenom, resBdenom, vintdenom,vintedenom,true);
    vint/=vintdenom;
    vinte/=vintdenom;
    for(int i = 0; i<hpt->GetN(); i++) {
      double ef = hpt->GetEY()[i]/hpt->GetY()[i];
      hpt->GetY()[i]/=hdenom->GetY()[i];
      hpt->GetEY()[i]=hpt->GetY()[i]*sqrt(ef*ef+pow(hdenom->GetEY()[i]/hdenom->GetY()[i],2));
      
      ef = hA->GetEY()[i]/hA->GetY()[i];
      hA->GetY()[i]/=hAdenom->GetY()[i];
      hA->GetEY()[i]=hA->GetY()[i]*sqrt(ef*ef+pow(hAdenom->GetEY()[i]/hAdenom->GetY()[i],2));
      
      ef = hB->GetEY()[i]/hB->GetY()[i];
      hB->GetY()[i]/=hBdenom->GetY()[i];
      hB->GetEY()[i]=hB->GetY()[i]*sqrt(ef*ef+pow(hBdenom->GetEY()[i]/hBdenom->GetY()[i],2));
    }
  } else if(chi7noeff) {
    hpt = GetVNPt(N723NOEFF, bin, EtaMin,EtaMax, hA, hB,nwspec,resA, resB, vint,vinte,true);
    fin->Close();
    if(hdenom==NULL) return;
    fin = new TFile(rootFile.data(),"r");
    hdenom = GetVNPt(D2432NOEFF, bin, EtaMin,EtaMax, hAdenom, hBdenom,nwspec2,resAdenom,resBdenom, vintdenom,vintedenom,true);
    vint/=vintdenom;
    vinte/=vintdenom;
    for(int i = 0; i<hpt->GetN(); i++) {
      double ef = hpt->GetEY()[i]/hpt->GetY()[i];
      hpt->GetY()[i]/=hdenom->GetY()[i];
      hpt->GetEY()[i]=hpt->GetY()[i]*sqrt(ef*ef+pow(hdenom->GetEY()[i]/hdenom->GetY()[i],2));
      
      ef = hA->GetEY()[i]/hA->GetY()[i];
      hA->GetY()[i]/=hAdenom->GetY()[i];
      hA->GetEY()[i]=hA->GetY()[i]*sqrt(ef*ef+pow(hAdenom->GetEY()[i]/hAdenom->GetY()[i],2));
      
      ef = hB->GetEY()[i]/hB->GetY()[i];
      hB->GetY()[i]/=hBdenom->GetY()[i];
      hB->GetEY()[i]=hB->GetY()[i]*sqrt(ef*ef+pow(hBdenom->GetEY()[i]/hBdenom->GetY()[i],2));
    }
  }
