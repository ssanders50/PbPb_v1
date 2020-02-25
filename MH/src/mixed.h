#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TGraphErrors.h"

static const double MINPT = 0.3;
static const double MAXPT = 8.0;

enum Mixed {N2,N3,N4,N5,N6,N7,N42,N523,N62,N63,N723,D24,D26,D34,D2232,D2432};

string MixedName[] {
		 "N2","N3","N4","N5","N6","N7","N42","N523","N62","N63","N723","D24","D26","D34","D2232","D2432"
};

string mixedDirs[]{
  "~/PbPb_2015/MixedHarmonics/results/v2/results/results_trackmid2/2015_N2SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/v3/results/results_trackmid3/2015_N3SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/v4/results/results_trackmid4/2015_N4SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/v5/results/results_trackmid5/2015_N5SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/v6/results/results_trackmid6/2015_N6SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/v7/results/results_trackmid7/2015_N7SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/v42/results/results_trackmid2/2015_N42SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/v523/results/results_trackmid2/2015_N523SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/v62/results/results_trackmid2/2015_N62SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/v63/results/results_trackmid3/2015_N63SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/v723/results/results_trackmid2/2015_N723SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/D24/results/results_trackmid2/2015_D24SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/D26/results/results_trackmid2/2015_D26SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/D34/results/results_trackmid3/2015_D34SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/D2232/results/results_trackmid2/2015_D2232SUB3/",
    "~/PbPb_2015/MixedHarmonics/results/D2432/results/results_trackmid2/2015_D2432SUB3/"};

string mbaseNames[]{
  "PbPb_2015_N2SUB3_v2_HFm2",
    "PbPb_2015_N3SUB3_v3_HFm3",
    "PbPb_2015_N4SUB3_v4_HFm4",
    "PbPb_2015_N5SUB3_v5_HFm5",
    "PbPb_2015_N6SUB3_v6_HFm6",
    "PbPb_2015_N7SUB3_v7_HFm7",
    "PbPb_2015_N42SUB3_v4_HFm4",
    "PbPb_2015_N523SUB3_v5_HFm5",
    "PbPb_2015_N62SUB3_v6_HFm6",
    "PbPb_2015_N63SUB3_v6_HFm6",
    "PbPb_2015_N723SUB3_v7_HFm7",
    "PbPb_2015_D24SUB3_v2_HFm2",
    "PbPb_2015_D26SUB3_v2_HFm2",
    "PbPb_2015_D34SUB3_v3_HFm3",
    "PbPb_2015_D2232SUB3_v2_HFm2",
    "PbPb_2015_D2432SUB3_v2_HFm2"
    };

string pbaseNames[]{
  "PbPb_2015_N2SUB3_v2_HFp2",
    "PbPb_2015_N3SUB3_v3_HFp3",
    "PbPb_2015_N4SUB3_v4_HFp4",
    "PbPb_2015_N5SUB3_v5_HFp5",
    "PbPb_2015_N6SUB3_v6_HFp6",
    "PbPb_2015_N7SUB3_v7_HFp7",
    "PbPb_2015_N42SUB3_v4_HFp4",
    "PbPb_2015_N523SUB3_v5_HFp5",
    "PbPb_2015_N62SUB3_v6_HFp6",
    "PbPb_2015_N63SUB3_v6_HFp6",
    "PbPb_2015_N723SUB3_v7_HFp7",
    "PbPb_2015_D24SUB3_v2_HFp2",
    "PbPb_2015_D26SUB3_v2_HFp2",
    "PbPb_2015_D34SUB3_v3_HFp3",
    "PbPb_2015_D2232SUB3_v2_HFp2",
    "PbPb_2015_D2432SUB3_v2_HFp2"
    };

TH2D * getSPVN(int en=N2, string hf="m", string sub="", string centrange="0_5"){
  string exname = mixedDirs[en];
  if(hf=="m") {
    exname+=mbaseNames[en]+sub+".root";
  } else {
    exname+=pbaseNames[en]+sub+".root";
  }
  TFile * tf = new TFile(exname.data(),"read");
  string spname = centrange+"/spVn";
  string clonename = exname+"spVN_"+centrange;
  cout<<exname<<endl;  
  TH2D * h = (TH2D *) tf->Get(spname.data())->Clone(clonename.data());
  h->SetDirectory(0);
  tf->Close();
  return h;
};

TH2D * getSPVNnum(int en=N2, string hf="m", string sub="", string centrange="0_5"){
  string exname = mixedDirs[en];
  if(hf=="m") {
    exname+=mbaseNames[en]+sub+".root";
  } else {
    exname+=pbaseNames[en]+sub+".root";
  }
  TFile * tf = new TFile(exname.data(),"read");
  string spname = centrange+"/spVnnum";
  string clonename = exname+"spVNnum_"+centrange;
  cout<<exname<<endl;  
  TH2D * h = (TH2D *) tf->Get(spname.data())->Clone(clonename.data());
  h->SetDirectory(0);
  tf->Close();
  return h;
};

TH2D * getSPint(int en=N2, string hf="m", string sub="", string centrange="0_5"){
  string exname = mixedDirs[en];
  if(hf=="m") {
    exname+=mbaseNames[en]+sub+".root";
  } else {
    exname+=pbaseNames[en]+sub+".root";
  }
  TFile * tf = new TFile(exname.data(),"read");
  string spname = centrange+"/spInt";
  string clonename = exname+"spInt_"+centrange;
  TH2D * h = (TH2D *) tf->Get(spname.data())->Clone(clonename.data());
  h->SetDirectory(0);
  tf->Close();
  return h;
};

TH1D * getavpt(int en=N2, string hf="m", string sub="", string centrange="0_5"){
  string exname = mixedDirs[en];
  if(hf=="m") {
    exname+=mbaseNames[en]+sub+".root";
  } else {
    exname+=pbaseNames[en]+sub+".root";
  }
  TFile * tf = new TFile(exname.data(),"read");
  string spname = centrange+"/avpt";
  string clonename = exname+"avpt_"+centrange;
  TH1D * h = (TH1D *) ((TH2D *) tf->Get(spname.data()))->ProjectionX(clonename.data(),5,8);
  h->SetDirectory(0);
  h->Scale(0.25);
  tf->Close();
  return h;
};


TGraphErrors * getPt(int en =N2, string centrange="0_5"){
  double x[40];
  double y[40];
  double ex [40];
  double ey[40];
  TH2D * hm = getSPVN(en,"m","",centrange);
  TH2D * hp = getSPVN(en,"p","",centrange);
  TH1D * pt = getavpt(en,"m","",centrange);
  int npt = 0;
  for(int i = 1; i<=hm->GetNbinsX(); i++ ) {
    if(pt->GetBinContent(i)>MINPT && pt->GetBinContent(i) < MAXPT) {
      x[npt] = pt->GetBinContent(i);
      double ym = hm->GetBinContent(i,7) + hm->GetBinContent(i,8);
      double yp = hm->GetBinContent(i,5) + hm->GetBinContent(i,6);
      double yme = pow(hm->GetBinError(i,7),2) + pow(hm->GetBinError(i,8),2);
      double ype = pow(hm->GetBinError(i,5),2) + pow(hm->GetBinError(i,6),2);
      ex[npt] = 0;
      y[npt] = (ym+yp)/4.;
      ey[npt]=sqrt(yme+ype);
      ++npt;
    }
  }
  return new TGraphErrors(npt,x,y,ex,ey);
};


TGraphErrors * getPtNum(int en =N2, string centrange="0_5"){
  double x[40];
  double y[40];
  double ex [40];
  double ey[40];
  TH2D * hm = getSPVNnum(en,"m","",centrange);
  TH2D * hp = getSPVNnum(en,"p","",centrange);
  TH1D * pt = getavpt(en,"m","",centrange);
  int npt = 0;
  for(int i = 1; i<=hm->GetNbinsX(); i++ ) {
    if(pt->GetBinContent(i)>MINPT && pt->GetBinContent(i) < MAXPT) {
      x[npt] = pt->GetBinContent(i);
      double ym = hm->GetBinContent(i,7) + hm->GetBinContent(i,8);
      double yp = hm->GetBinContent(i,5) + hm->GetBinContent(i,6);
      double yme = pow(hm->GetBinError(i,7),2) + pow(hm->GetBinError(i,8),2);
      double ype = pow(hm->GetBinError(i,5),2) + pow(hm->GetBinError(i,6),2);
      ex[npt] = 0;
      y[npt] = (ym+yp)/4.;
      ey[npt]=sqrt(yme+ype);
      ++npt;
    }
  }
  return new TGraphErrors(npt,x,y,ex,ey);
};

TGraphErrors * getShengquan(int en = N42, string centrange="0_5"){
  string sn= "v1/"+MixedName[en]+"_"+centrange+".txt";
  cout<<sn<<endl;
  return new TGraphErrors (sn.data(),"%lg %lg %lg");
}

TGraphErrors * getShengquan(string enname="chi42", string centrange="0_5"){
  string sn= "v1/"+enname+"_"+centrange+".txt";
  cout<<sn<<endl;
  return new TGraphErrors (sn.data(),"%lg %lg %lg");
}
