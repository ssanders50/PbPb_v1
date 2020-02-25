TFile * tr = new TFile("MH_hists.root");
TFile * tf = new TFile("~/PbPb_2015_flat/MH/macros/MH_hists.root");
TBrowser br;
TGraphErrors * gr;
TGraphErrors * gf;
TGraphErrors * r;
void CheckFlat(){
  gr = (TGraphErrors *) tr->Get("N3SUB2/-1.6_1.6/25_30/g");
  gr->SetMarkerStyle(24);
  gr->SetMarkerColor(kRed);
  gr->SetLineColor(kRed);
  gf = (TGraphErrors *) tf->Get("N3SUB2/-1.6_1.6/25_30/g");
  gf->SetMarkerStyle(25);
  gf->SetMarkerColor(kBlue);
  gf->SetLineColor(kBlue);
  r = (TGraphErrors *) gr->Clone("ratio");
  for(int i = 0; i<gr->GetN(); i++) {
    r->GetY()[i]/=gf->GetY()[i];
    double A = gr->GetY()[i];
    double B = gf->GetY()[i];
    double sA = gr->GetEY()[i];
    double sB = gf->GetEY()[i];
    r->GetEY()[i] = r->GetY()[i]*sA/A;
  }
  TCanvas * c = new TCanvas("c2","c2",800,1200);
  c->Divide(1,2);
  c->cd(1);
  TH1D * h2 = new TH1D("h2","h2",100,0,12);
  h2->SetMaximum(0.3);
  h2->SetXTitle("p_{T} (GeV/c)");
  h2->SetYTitle("v_{3}");
  h2->Draw();
  gr->Draw("p");
  gf->Draw("p");
  c->cd(2);
  TH1D * hr = new TH1D("hr","hr",100,0,12);
  hr->SetMinimum(0.97);
  hr->SetMaximum(1.03);
  hr->SetXTitle("p_{T} (GeV/c)");
  hr->SetYTitle("Ratio");
  hr->Draw();
  r->Draw("p");
}
