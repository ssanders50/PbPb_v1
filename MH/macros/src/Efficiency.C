enum    TrackType {typeUndefined = 0, ppReco = 1, HIReco, Pixel};
enum TrackQuality {qualityUndefined = 0, loose = 1, normal, tight};
TrackType sTrackType;
TrackQuality sTrackQuality;
TrackType SetTracking( ){
  TFile * fin = new TFile(rootFile.data(),"read");
  TDirectory * d = (TDirectory *) fin->Get("vnanalyzer/Conditions");
  TList * l = (TList *) d->GetListOfKeys();
  int indx = 0;
  sTrackType = typeUndefined;
  sTrackQuality = qualityUndefined;
  while(l->At(indx) != l->Last()) {
    string condition = l->At(indx++)->GetName();
    if(condition == "hiGeneralAndPixelTracks") sTrackType = Pixel;
    if(condition == "hiGeneralTracks") sTrackType = HIReco;
    if(condition == "generalTracks") sTrackType = ppReco;
    if(sTrackType == Pixel) {
      cout<<"Pixel:"<<condition<<":"<<endl;
      if(condition == "dzdzerror_0002.00") sTrackQuality = normal;
      if(condition == "dzdzerror_0005.00") sTrackQuality = loose;
      if(condition == "dzdzerror_0001.50") sTrackQuality = tight;
    }

    cout<<condition<<endl;
  }
  fin->Close();
  return sTrackType;
}
double FakeAndEff(int cent, double pt, double emin, double emax, double &eff) {
  double cb[14]={0,5,10,15,20,25,30,35,40,50,60,70,80,100};
  double cbe[6]={0,5,10,30,50,100};
  TFile * f=0;
  TFile * e=0;
  eff = 1.;
  if(sTrackType == Pixel && sTrackQuality == normal) {
    f = new TFile("EffAndFake/FakeRatesPixelPbPb_tight.root");
    e = new TFile("EffAndFake/EffCorrectionsPixelPbPb_tight.root");
  }
  if(sTrackType == Pixel && sTrackQuality == tight){ 
    f = new TFile("EffAndFake/FakeRatesPixelPbPb_tight.root");
    e = new TFile("EffAndFake/EffCorrectionsPixelPbPb_tightB.root");
  }
  if(sTrackType == Pixel && sTrackQuality == loose){ 
    f = new TFile("EffAndFake/FakeRatesPixelPbPb_loose.root");
    e = new TFile("EffAndFake/EffCorrectionsPixelPbPb_loose.root");
  }
  TH1I * cen = new TH1I("cen","cen",13,cb);
  TH1I * cene = new TH1I("cene","cene",5,cbe);
  int ib = cen->FindBin(cent)-1;
  int ibe = cene->FindBin(cent)-1;
  string rc = "hfak_"+to_string((int)cb[ib])+"_"+to_string((int)cb[ib+1]);
  TH2D * hf = (TH2D *) f->Get(rc.data());
  string re = "Eff_"+to_string((int)cbe[ibe])+"_"+to_string((int)cbe[ibe+1]);
  TH2D * he = (TH2D *) e->Get(re.data());
  int ptbin = hf->GetYaxis()->FindBin(pt);
  int etabinmin = hf->GetXaxis()->FindBin(emin+0.001);
  int etabinmax = hf->GetXaxis()->FindBin(emax-0.001);
  double val = 0;
  eff = 0;
  for(int i = etabinmin; i<=etabinmax; i++) {
    val += hf->GetBinContent(i,ptbin);
    eff += he->GetBinContent(i,ptbin);
  }
  val /=(double)(etabinmax-etabinmin+1);
  eff /=(double)(etabinmax-etabinmin+1);
  cen->Delete();
  cene->Delete();
  f->Close();
  e->Close();
  return val ;
}



TH2D * ptcntEff(TH2D * ptcnt, double cent) {
  double cbe[6]={0,5,10,30,50,100};
  TFile * e=0;
  bool skipeff = true;
  if(!skipeff) {
    if(sTrackType == Pixel && sTrackQuality == normal)  e = new TFile("EffAndFake/EffCorrectionsPixelPbPb_tight.root");
    if(sTrackType == Pixel && sTrackQuality == tight)  e = new TFile("EffAndFake/EffCorrectionsPixelPbPb_tightB.root");
    if(sTrackType == Pixel && sTrackQuality == loose)  e = new TFile("EffAndFake/EffCorrectionsPixelPbPb_loose.root");
  }
  TH1I * cene = new TH1I("cene","cene",5,cbe);
  int ibe = cene->FindBin(cent)-1;
  string re = "Eff_"+to_string((int)cbe[ibe])+"_"+to_string((int)cbe[ibe+1]);
  TH2D * he=NULL;
  if(!skipeff)  he = (TH2D *) e->Get(re.data());
  TH2D * hsEff = (TH2D *) ptcnt->Clone("ptcntEff");
  hsEff->Reset();
  hsEff->SetDirectory(0);
  //  if(AnalNames[ANAL]==AnalNames[N2EFF] || AnalNames[ANAL]==AnalNames[N723EFF] || AnalNames[ANAL]==AnalNames[D2432EFF]
  //   || AnalNames[ANAL]==AnalNames[CHI7EFF] || AnalNames[ANAL]==AnalNames[N42EFF]) skipeff=true;
  for(int i = 1; i<=ptcnt->GetNbinsX(); i++) {
    for(int j = 1; j<=ptcnt->GetNbinsY(); j++) {
      double pt = ptcnt->GetXaxis()->GetBinCenter(i);
      double eta = ptcnt->GetYaxis()->GetBinCenter(j);
      double eff = 1.;
      if(!skipeff) {
	int ptbin = he->GetYaxis()->FindBin(pt);
	int etabin = he->GetXaxis()->FindBin(eta);
	double eff =  he->GetBinContent(etabin,ptbin);
      }
      if(eff<=0 || skipeff) eff = 1;
      hsEff->SetBinContent(i,j,ptcnt->GetBinContent(i,j)/eff);
    }
  }
  cene->Delete();
  if(!skipeff) e->Close();
  return hsEff ;
}
