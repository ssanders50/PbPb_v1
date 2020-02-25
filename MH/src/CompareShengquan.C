#include "mixed.h"
string centranges[]={"0_5","5_10","10_15","15_20","20_25","25_30","30_35","35_40","50_60"};
string centlabels[]={"0-5\%","5-10\%","10-15\%","15-20\%","20-25\%","25-30\%","30-35\%",
		     "35-40\%","50-60\%"};
void compare(int en=N42, string ytitle="v_{4} (#Psi_{2})", double miny = -0.0999, double maxy=0.1) {
  TCanvas * c = new TCanvas(MixedName[en].data(),MixedName[en].data(),1400,1100);
  c->Divide(3,3,0,0);
  TH1D * h = new TH1D("h","h",100,0,8);
  h->SetMinimum(miny);
  h->SetMaximum(maxy);
  h->SetXTitle("p_{T} (GeV/c)");
  h->SetYTitle (ytitle.data());
  TPaveText * ptext[9];
  TGraphErrors * gr[9];
  TGraphErrors * sgr[9];
  for(int i = 0; i<9; i++) {
    c->cd(i+1);
    h->Draw();
    ptext[i] = new TPaveText(0.7,0.8,0.9,0.95,"NDC");
    ptext[i]->AddText(centlabels[i].data());
    ptext[i]->SetTextFont(43);
    ptext[i]->SetTextSize(24);
    ptext[i]->SetFillColor(kWhite);
    ptext[i]->SetBorderSize(0);
    ptext[i]->Draw();
    gr[i] = getPt(en,centranges[i]);
    gr[i]->SetMarkerStyle(20);
    gr[i]->SetMarkerColor(kBlue);
    gr[i]->SetLineColor(kBlue);
    gr[i]->Draw("p");
    sgr[i] = getShengquan(en,centranges[i]);
    //for(int j = 0; j<sgr[i]->GetN(); j++) {
    //  sgr[i]->GetY()[j]*=10000.;
    //  sgr[i]->GetEY()[j]*=10000.;
    //}
    sgr[i]->SetMarkerStyle(20);
    sgr[i]->SetMarkerColor(kRed);
    sgr[i]->SetLineColor(kRed);
    sgr[i]->Draw("p");
  }
  string cnameout = "figures/"+MixedName[en]+".pdf";
  c->Print(cnameout.data(),"pdf");
}

void compareNum(int en=N42, string ytitle="v_{4} (#Psi_{2})", double miny = -0.0999, double maxy=0.1) {

  TCanvas * c = new TCanvas(MixedName[en].data(),MixedName[en].data(),1400,1100);
  c->Divide(3,3,0,0);
  TH1D * h = new TH1D("h","h",100,0,8);
  h->SetMinimum(miny);
  h->SetMaximum(maxy);
  h->SetXTitle("p_{T} (GeV/c)");
  h->SetYTitle (ytitle.data());
  TPaveText * ptext[9];
  TGraphErrors * gr[9];
  TGraphErrors * sgr[9];
  for(int i = 0; i<9; i++) {
    c->cd(i+1);
    h->Draw();
    ptext[i] = new TPaveText(0.7,0.8,0.9,0.95,"NDC");
    ptext[i]->AddText(centlabels[i].data());
    ptext[i]->SetTextFont(43);
    ptext[i]->SetTextSize(24);
    ptext[i]->SetFillColor(kWhite);
    ptext[i]->SetBorderSize(0);
    ptext[i]->Draw();
    gr[i] = getPtNum(en,centranges[i]);
    gr[i]->SetMarkerStyle(20);
    gr[i]->SetMarkerColor(kBlue);
    gr[i]->SetLineColor(kBlue);
    gr[i]->Draw("p");
    sgr[i] = getShengquan(en,centranges[i]);
    //for(int j = 0; j<sgr[i]->GetN(); j++) {
    //  sgr[i]->GetY()[j]*=10000.;
    //  sgr[i]->GetEY()[j]*=10000.;
    //}
    sgr[i]->SetMarkerStyle(20);
    sgr[i]->SetMarkerColor(kRed);
    sgr[i]->SetLineColor(kRed);
    sgr[i]->Draw("p");
  }
  string cnameout = "figures/"+MixedName[en]+"_NumOnly.pdf";
  c->Print(cnameout.data(),"pdf");
}

void chi(int en=N42, int en2 = D24, string ename="chi42", string ytitle="#Chi_{4}", double miny = -0.0999, double maxy=0.1) {
  TCanvas * c = new TCanvas(ename.data(),ename.data(),1400,1100);
  c->Divide(3,3,0,0);
  TH1D * h = new TH1D("h","h",100,0,8);
  h->SetMinimum(miny);
  h->SetMaximum(maxy);
  h->SetXTitle("p_{T} (GeV/c)");
  h->SetYTitle (ytitle.data());
  TPaveText * ptext[9];
  TGraphErrors * gr[9];
  TGraphErrors * grn[9];
  TGraphErrors * sgr[9];
  for(int i = 0; i<9; i++) {
    c->cd(i+1);
    h->Draw();
    ptext[i] = new TPaveText(0.7,0.8,0.9,0.95,"NDC");
    ptext[i]->AddText(centlabels[i].data());
    ptext[i]->SetTextFont(43);
    ptext[i]->SetTextSize(24);
    ptext[i]->SetFillColor(kWhite);
    ptext[i]->SetBorderSize(0);
    ptext[i]->Draw();
    gr[i] = getPt(en,centranges[i]);
    gr[i]->SetMarkerStyle(20);
    gr[i]->SetMarkerColor(kBlue);
    gr[i]->SetLineColor(kBlue);
    gr[i]->Draw("p");
    grn[i] = getPt(en2,centranges[i]);
    for(int j = 0; j<gr[i]->GetN(); j++) {
      gr[i]->GetY()[j] /= grn[i]->GetY()[j];
      gr[i]->GetEY()[j] /= grn[i]->GetY()[j];
    }
    sgr[i] = getShengquan(ename,centranges[i]);
    sgr[i]->SetMarkerStyle(20);
    sgr[i]->SetMarkerColor(kRed);
    sgr[i]->SetLineColor(kRed);
    sgr[i]->Draw("p");
  }
  string cnameout = "figures/"+ename+".pdf";
  c->Print(cnameout.data(),"pdf");
}


void CompareShengquan(){
  //chi(N42,D24,"Chi42", "#Chi_{4}", -0.01, 2.0);
  //chi(N523,D2232,"Chi523","Chi_{5}",-0.01,2.999);
  //chi(N62,D26, "Chi62","Chi_{62}",-0.01,2.999);
  //chi(N63,D34, "Chi63","Chi_{63}",-0.01,2.999);
  //chi(N723,D2432,"Chi723","Chi_P{7}",-0.01,3.999);
  //compare(N523,"v_{5} (#Psi_{23})", -0.01, 0.0799);
  //compare(N42,"v_{4} (#Psi_{2})", -0.01, 0.0699);
  compareNum(N42,"v_{4} (#Psi_{2})", -0.0001, 0.000699);
  //compare(N62,"v_{6} (#Psi_{2})", -0.01, 0.0299);
  //compare(N62,"v_{6} (#Psi_{2})", -0.01, 0.0299);
  //compare(N63,"v_{6} (#Psi_{3})", -0.01, 0.0299);
  //compare(N723,"v_{7} (#Psi_{23})", -0.01, 0.0299);
  //compare(D24,"D24",-0.01,0.0599);
  //compare(D26,"D26",-0.01,0.0399);
  //compare(D34,"D34",-0.01,0.0399);
  //compare(D2232,"D2232",-0.01,0.0399);
  //compare(D2432,"D2232",-0.01,0.0399);
  //compareNum(N523,"v_{5} (#Psi_{23})", -0.00001, 0.0000799);
  //compareNum(N62,"v_{6} (#Psi_{2})", -0.00001, 0.0000299);
  //compareNum(N63,"v_{6} (#Psi_{3})", -0.00001, 0.0000299);
  //compareNum(N723,"v_{7} (#Psi_{23})", -0.000001, 0.00000299);
  //compareNum(D24,"D24",-0.0001,0.000599);
  //compareNum(D26,"D26",-0.00001,0.0000399);
  //compareNum(D34,"D34",-0.00001,0.0000399);
  //compareNum(D2432,"D2432",-0.000001,0.00000399);

};
