double fake(int cent, double eta, double pt) {
  double cb[14]={0,5,10,15,20,25,30,35,40,50,60,70,80,100};
  TFile * f = new TFile("EffAndFake/FakeRatesPixelPbPb_nominal.root");
  TH1I * cen = new TH1I("cen","cen",13,cb);
  int ib = cen->FindBin(cent);
  string rc = "hfak_"+to_string((int)cb[ib])+"_"+to_string((int)cb[ib+1]);
  TH2D * hf = (TH2D *) f->Get(rc.data());
  int ptbin = hf->GetYaxis()->FindBin(pt);
  int etabin = hf->GetXaxis()->FindBin(eta);
  double val = hf->GetBinContent(etabin,ptbin);
  cen->Delete();
  f->Close();
  return val ;	   
}
