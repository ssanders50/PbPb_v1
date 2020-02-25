TFile * tf = new TFile("MH_hists.root");
TGraphErrors * gintc;
TGraphErrors * gintd;
TGraphErrors * ginte;
TGraphErrors * gintf;

void v1odd(string cent="25_30",string eta="0.4_0.8" ,string sub = "SUB3"){
  gintc = (TGraphErrors *) tf->Get(Form("N1HFc%s/%s/%s/gint",sub.data(),eta.data(),cent.data()));
  gintd = (TGraphErrors *) tf->Get(Form("N1HFd%s/%s/%s/gint",sub.data(),eta.data(),cent.data()));
  ginte = (TGraphErrors *) tf->Get(Form("N1HFe%s/%s/%s/gint",sub.data(),eta.data(),cent.data()));
  gintf = (TGraphErrors *) tf->Get(Form("N1HFf%s/%s/%s/gint",sub.data(),eta.data(),cent.data()));
  int minc = 0;
  int maxc = 0;
  if(cent=="0_5") {minc=0; maxc=5;}
  if(cent=="5_10") {minc=5; maxc=10;}
  if(cent=="10_15") {minc=10; maxc=15;}
  if(cent=="15_20") {minc=15; maxc=20;}
  if(cent=="20_25") {minc=20; maxc=25;}
  if(cent=="25_30") {minc=25; maxc=30;}
  if(cent=="30_35") {minc=30; maxc=35;}
  if(cent=="35_40") {minc=35; maxc=40;}
  if(cent=="40_50") {minc=40; maxc=50;}
  if(cent=="50_60") {minc=50; maxc=60;}
  if(cent=="60_70") {minc=60; maxc=70;}
  if(cent=="0_20") {minc=0; maxc=20;}
  if(cent=="20_60") {minc=20; maxc=60;}
  TCanvas * c = new TCanvas("c","c",900,750);
  TH1D * h = new TH1D("h","h",100,-3,3);
  h->SetMinimum(-0.02);
  h->SetMaximum(0.02);
  h->SetXTitle("#eta");
  h->SetYTitle("v_{1}");
  h->Draw();
  gintc->Draw("p");
  gintd->SetMarkerStyle(20);
  gintd->SetMarkerColor(kBlue);
  gintd->SetLineColor(kBlue);
  gintd->Draw("p");
  ginte->SetMarkerStyle(24);
  ginte->SetMarkerColor(kGreen);
  ginte->SetLineColor(kGreen);
  ginte->Draw("p");
  gintf->SetMarkerStyle(25);
  gintf->SetMarkerColor(kMagenta);
  gintf->SetLineColor(kMagenta);
  gintf->Draw("p");
  TLatex * l1 = new TLatex(-2.6,0.016,Form("%d - %d%c",minc,maxc,'%'));
  l1->SetTextFont(43);
  l1->SetTextSize(30);
  l1->Draw();
  TLegend * leg = new TLegend(0.55,0.7,0.8,0.9);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(43);
  leg->SetTextSize(24);
  leg->AddEntry(gintc,"3.0 < |#eta_{EP}| < 3.5","lp");
  leg->AddEntry(gintd,"3.5 < |#eta_{EP}| < 4.0","lp");
  leg->AddEntry(ginte,"4.0 < |#eta_{EP}| < 4.5","lp");
  leg->AddEntry(gintf,"4.5 < |#eta_{EP}| < 5.0","lp");
  leg->Draw();
  c->Print(Form("v1odd/v1odd_%s_%s.pdf",cent.data(),sub.data()),"pdf");
}
