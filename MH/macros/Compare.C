double maxR(double val){
  double sign = 1.;
  if(val<0) sign = -1.;
  val=abs(val);
  double ex = trunc(log10(val));
  double rem = log10(val)- trunc(log10(val));
  double rn = 0;
  double remck = 0.8*rem;
  cout<<val<<"\t"<<remck<<endl;
  if(remck>0) {
    if(remck<log10(1)) {
      rn = log10(1);
    } else if (remck<log10(2)){
      rn = log10(2);
    } else if (remck<log10(4)){
      rn = log10(4);
    } else if (remck<log10(5)){
      rn = log10(5);
    } else if (remck<log10(10)){
      rn = log10(10);
    }
  } else {
    if(remck<log10(0.1)) {
      rn = log10(0.1);
    } else if (remck<log10(.2)){
      rn = log10(.2);
    } else if (remck<log10(.4)){
      rn = log10(.4);
    } else if (remck<log10(.5)){
      rn = log10(.5);
    } else if (remck<log10(1.)){
      rn = log10(1.0);
    }
  }
  cout<<rn<<endl;
  double ret = sign*pow(10,ex+rn);
  return ret;
}

void Compare2(string dir1, string g1, string dir2, string g2){
  TCanvas * c = new TCanvas("compare","compare",450,800);
  c->Divide(1,3);
  c->cd(1);
  string A = dir1+"/"+g1;
  string B = dir2+"/"+g2;
  TGraphErrors * gA = new TGraphErrors(A.data(),"%lg %lg %lg");
  TGraphErrors * gB = new TGraphErrors(B.data(),"%lg %lg %lg");
  gA->SetMarkerStyle(20);
  gA->SetMarkerColor(kBlue);
  gB->SetMarkerStyle(20);
  gB->SetMarkerColor(kRed);
  double xminA,yminA,xmaxA,ymaxA;
  gA->ComputeRange(xminA,yminA,xmaxA,ymaxA);
  double xminB,yminB,xmaxB,ymaxB;
  gB->ComputeRange(xminB,yminB,xmaxB,ymaxB);
  TH1D * h = new TH1D("h","h",100,0,12);
  double setymin = 0;
  if(min(yminA,yminB)<0) setymin = maxR(min(yminA,yminB)); 
  double setymax = maxR(max(ymaxA,ymaxB));
  h->SetMinimum(setymin);
  h->SetMaximum(setymax);
  h->Draw();
  gA->Draw("p");
  gB->Draw("p");
  TGraphErrors * gRatio = (TGraphErrors *) gA->Clone("Ratio");
  for(int i = 0; i<gA->GetN(); i++){ 
    if(gB->GetY()[i]!=0) {
      gRatio->GetY()[i]/=gB->GetY()[i]; 
      gRatio->GetEY()[i] = gRatio->GetY()[i]*gA->GetEY()[i]/gA->GetY()[i];
    }
  }
  c->cd(2);
  TH1D * hr = new TH1D("hr","hr",100,0,12);
  hr->SetMinimum(0.9);
  hr->SetMaximum(1.1);
  hr->Draw();
  gRatio->Draw("p");
  TGraphErrors * gDiff = (TGraphErrors *) gA->Clone("Ratio");
  for(int i = 0; i<gA->GetN(); i++){ 
    gDiff->GetY()[i]=(gB->GetY()[i]-gA->GetY()[i]); 
    gDiff->GetEY()[i] = gA->GetEY()[i];
  }
  gDiff->ComputeRange(xminA,yminA,xmaxA,ymaxA);
  c->cd(3);
  TH1D * hd = new TH1D("hd","hd",100,0,12);
  setymin = 0;
  if(yminA<0) setymin = maxR(yminA); 
  setymax = maxR(ymaxA);
  hd->SetMinimum(setymin);
  hd->SetMaximum(setymax);
  hd->Draw();
  gDiff->Draw("p");
}

void Compare(){
  Compare2("/home/sanders/PbPb_2015/MH/macros/figures_MH/N2SUB3/eta_-0.8_00.8_decor/data",
	   "N2SUB3_0_5_eta_-0.8_0.8_A.dat",
	   "/home/sanders/PbPb_2015/MH/macros/figures_MH_tight2/N2SUB3/eta_-0.8_00.8_decor/data",
	   "N2SUB3_0_5_eta_-0.8_0.8_A.dat");

}
