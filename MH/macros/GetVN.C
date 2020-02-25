#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TMath.h"
#include "TStopwatch.h"
#include <iostream>

#include "src/HiEvtPlaneList.h"
using namespace hi;
static const int ncentbinsNOFF = 25;
static const int centBinsNOFF[]={0, 10, 20, 30, 40, 50, 60, 70, 80, 100, 120, 135, 150, 160, 185, 210, 230, 250, 270, 300, 330, 350, 370, 390, 420, 500};
static const double centRefBinsNOFF[]={0, 10, 20, 30, 40, 50, 60, 70, 80, 100, 120, 135, 150, 160, 185, 210, 230, 250, 270, 300, 330, 350, 370, 390, 420, 500};
static const int cbinsNOFF = 25;
static const int cminNOFF[]={1, 10, 20, 30, 40, 50, 60, 70, 80, 100, 120, 135, 150, 160, 185, 210, 230, 250, 270, 300, 330, 350, 370, 390, 420};
static const int cmaxNOFF[]={10, 20, 30, 40, 50, 60, 70, 80, 100, 120, 135, 150, 160, 185, 210, 230, 250, 270, 300, 330, 350, 370, 390, 420, 500};
static const int ncentbinsCENT = 11;
static const int centBinsCENT[]={0,5,10,15,20,25,30,35,40,50,60,70};
static const double centRefBinsCENT[]={0,5,10,15,20,25,30,35,40,50,60,70};
static const int cbinsCENT = 13;
static const int cminCENT[]={0, 5,10,15,20,25,30,35,40,50,60,  0,20, 60};
static const int cmaxCENT[]={5,10,15,20,25,30,35,40,50,60,70, 20,60,100};
bool ntrkbinning = false;
int ncentbins = 0;
int centBins[50];
double centRefBins[50];
int cbins = 0;
int cmin[50];
int cmax[50];
TFile * tout;
TDirectory * toutsub;
TDirectory * toutsubsub;
TDirectory * toutsubsubsub;
string tag;
bool SetToA = false;
bool Decor;
double EtaMin = -0.8;
double EtaMax = 0.8;
string FigDir = "";
string FigSubDir = "";
string FigSubSubDir = "";
FILE * outint;
string soutint;
string sspec;
FILE * outspec;
TFile * fin;
double fw = 1.3;
int ANAL = -1;
double fakescale = 1.;
bool isNominal = true;
bool isWide = false;
bool isNarrow = false;
bool isLoose = false;
bool isTight = false;
string stag;
TH1D * centbins;
TH1I * centRef;
TH1D * rcnt;
string rootFile;
double resA[50];
double resB[50];
double resAdenom[50];
double resBdenom[50];
double PTMAX = 0;
double VNMIN = 0;
double VNMAX=0;
double VNINTMIN=0;
double VNINTMAX=0;
#include "src/Types.h"
#include "src/Efficiency.C"
#include "src/flip2D.C"
#include "src/GetVNPt.C"
#include "src/Harmonics.h"
#include "src/drawSpec.C"
TH1D * h = 0;
void GetVNCreate(int replay , int bin , TGraphErrors * & gint, TGraphErrors * & gintA, TGraphErrors *& gintB,  bool plotit=true, bool NumOnly=false, bool DenomOnly=false ){
  TH1D * hspec = 0;
  string cname = ANALS[replay][0]+"_"+to_string(cmin[bin])+"_"+to_string(cmax[bin])+Form("_eta_%03.1f_%03.1f",EtaMin,EtaMax);
  h = new TH1D("h","h",100,0,PTMAX);
  h->SetDirectory(0);
  h->SetMinimum(0);

  h->SetMaximum(0.6);
  TGraphErrors * g;
  TGraphErrors * gA;
  TGraphErrors * gB;
  TGraphErrors * gspec;
  TGraphErrors * nwspec2;
  double ymin = 0;
  double ymax = 1;
  double vint = 0;
  double vinte = 0;
  double vintA = 0;
  double vintAe = 0;
  double vintB = 0;
  double vintBe = 0;

  if(replay==N1SUB2   || replay==N1SUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1ASUB2   || replay==N1ASUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1BSUB2   || replay==N1BSUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1HFm1cSUB2   || replay==N1HFm1cSUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1HFm1dSUB2   || replay==N1HFm1dSUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1HFm1eSUB2   || replay==N1HFm1eSUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1HFm1fSUB2   || replay==N1HFm1fSUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1HFp1cSUB2   || replay==N1HFp1cSUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1HFp1dSUB2   || replay==N1HFp1dSUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1HFp1eSUB2   || replay==N1HFp1eSUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1HFp1fSUB2   || replay==N1HFp1fSUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1HFcSUB2   || replay==N1HFcSUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1HFdSUB2   || replay==N1HFdSUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1HFeSUB2   || replay==N1HFeSUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1HFfSUB2   || replay==N1HFfSUB3)   g =   N1(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1MCm22SUB3 || replay==N1MCm18SUB3 || replay==N1MCm14SUB3 || replay==N1MCm10SUB3 ||
     replay==N1MCm06SUB3 || replay==N1MCm02SUB3 || replay==N1MCp22SUB3 || replay==N1MCp18SUB3 ||
     replay==N1MCp14SUB3 || replay==N1MCp10SUB3 ||  replay==N1MCp06SUB3 || replay==N1MCp02SUB3 )
    g =   N1EVEN(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1MCm22SUB2 || replay==N1MCm18SUB2 || replay==N1MCm14SUB2 || replay==N1MCm10SUB2 ||
     replay==N1MCm06SUB2 || replay==N1MCm02SUB2 || replay==N1MCp22SUB2 || replay==N1MCp18SUB2 ||     
     replay==N1MCp14SUB2 || replay==N1MCp10SUB2 ||  replay==N1MCp06SUB2 || replay==N1MCp02SUB2 )
    g =   N1EVEN(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N1EVENSUB2 || replay==N1EVENSUB3) g =   N1EVEN(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N112SUB2   || replay==N112SUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N112ASUB2   || replay==N112ASUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N112BSUB2   || replay==N112BSUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);

  if(replay==N112cSUB2   || replay==N112cSUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N112AcSUB2   || replay==N112AcSUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N112BcSUB2   || replay==N112BcSUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);

  if(replay==N112dSUB2   || replay==N112dSUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N112AdSUB2   || replay==N112AdSUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N112BdSUB2   || replay==N112BdSUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);

  if(replay==N112eSUB2   || replay==N112eSUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N112AeSUB2   || replay==N112AeSUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N112BeSUB2   || replay==N112BeSUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);

  if(replay==N112fSUB2   || replay==N112fSUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N112AfSUB2   || replay==N112AfSUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N112BfSUB2   || replay==N112BfSUB3)   g =   N112(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);

  // if(replay==N123SUB2   || replay==N123SUB3)   g =   N123(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  // if(replay==N123ASUB2   || replay==N123ASUB3)   g =   N123(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  // if(replay==N123BSUB2   || replay==N123BSUB3)   g =   N123(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N2SUB2   || replay==N2SUB3)   g =   N2(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N3SUB2   || replay==N3SUB3)   g =   N3(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N4SUB2   || replay==N4SUB3)   g =   N4(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N5SUB2   || replay==N5SUB3)   g =   N5(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N6SUB2   || replay==N6SUB3)   g =   N6(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N7SUB2   || replay==N7SUB3)   g =   N7(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N523SUB2 || replay==N523SUB3) g = N523(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N523ASUB2 || replay==N523ASUB3) g = N523(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N42SUB2   || replay==N42SUB3)   g =   N42(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N42ASUB2   || replay==N42ASUB3)   g =   N42(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==N42BSUB3)   g =   N42(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==N42CSUB3)   g =   N42(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N62SUB2   || replay==N62SUB3)   g =   N62(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N62ASUB3)   g =   N62(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N63SUB2   || replay==N63SUB3)   g =   N63(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N63ASUB2 || replay==N63ASUB3)   g =   N63(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==N63BSUB3)   g =   N63(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==N63CSUB3)   g =   N63(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==Chi4)    g = CHI4(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==Chi4A)   g = CHI4(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==Chi5)    g = CHI5(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==Chi5A)   g = CHI5(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==Chi62)    g = CHI62(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==Chi62A)   g = CHI62(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==Chi63)    g = CHI63(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==Chi63A)   g = CHI63(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==Chi7)    g = CHI7(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if( replay==Chi7A)   g = CHI7(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N723SUB2 || replay==N723SUB3) g = N723(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);
  if(replay==N723ASUB2 || replay==N723ASUB3) g = N723(replay,bin,EtaMin,EtaMax,ymin,ymax,g,gA,gB,gspec,gint,gintA, gintB,vint,vinte,vintA,vintAe,vintB,vintBe);

  double ymaxspec = 0;
  h->SetMinimum(ymin);
  h->SetMaximum(ymax);
  if(VNMIN>-10) h->SetMinimum(VNMIN);
  if(VNMAX>-10) h->SetMaximum(VNMAX);

  TCanvas * c=NULL;
  if(plotit) {
    c = new TCanvas(cname.data(),cname.data(),650,500);
    gPad->SetGrid(1,1);
    h->Draw();

    h->SetXTitle("P_{T} (GeV/c)");
  }
  string numdenom = "";
  if(NumOnly) numdenom=" (Numerator) ";
  if(DenomOnly) numdenom=" (Denominator) ";
 

  string yt = ANALS[replay][1]+numdenom+" ("+to_string(cmin[bin])+" #leq N_{trk}^{off} < "+to_string(cmax[bin])+")";
  if(!ntrkbinning) yt = ANALS[replay][1]+numdenom+" ("+to_string(cmin[bin])+" - "+to_string(cmax[bin])+"%)";

  FILE * fout;
  if(plotit) {

    h->SetYTitle(yt.data());
    if(strncmp(g->GetTitle(),"NOGOOD",6)!=0) g->Draw("p");  

    TLegend * leg = new TLegend(0.45,0.15,0.95,0.33);
    leg->SetTextFont(43);
    leg->SetTextSize(16);
    leg->SetFillColor(kWhite);
    leg->SetBorderSize(0);

    string s = "A+B only";
    if(strncmp(g->GetTitle(),"Graph",5)!=0) {
      s = g->GetTitle(); 
    }
    string append =Form("%5.4f#pm%5.4f",vint,vinte); 
    s+=" (<> = "+append+")";
    if(strncmp(g->GetTitle(),"NOGOOD",6)!=0) leg->AddEntry(g,s.data(),"lp");

    string sA = "A only";
    if(strncmp(gA->GetTitle(),"Graph",5)!=0) {
      sA = gA->GetTitle(); 
    }
    append =Form("%5.4f#pm%5.4f",vintA,vintAe); 
    sA+=" (<> = "+append+")";
    if(strncmp(gA->GetTitle(),"NOGOOD",6)!=0) leg->AddEntry(gA,sA.data(),"lp");

    string sB = "B only";
    if(strncmp(gB->GetTitle(),"Graph",5)!=0) {
      sB = gB->GetTitle(); 
    }
    append =Form("%5.4f#pm%5.4f",vintB,vintBe); 
    sB+=" (<> = "+append+")";
    if(strncmp(gB->GetTitle(),"NOGOOD",6)!=0) leg->AddEntry(gB,sB.data(),"lp");
    
    leg->Draw();

    if(strncmp(gA->GetTitle(),"NOGOOD",6)!=0) gA->Draw("p");
    if(strncmp(gB->GetTitle(),"NOGOOD",6)!=0) gB->Draw("p");
    if(strncmp(g->GetTitle(),"NOGOOD",6)!=0) g->Draw("p");
    TLatex * text = new TLatex(0.1*PTMAX,0.90*ymax,ANALS[replay][0].data());
    text->SetTextFont(43);
    text->SetTextSize(24);
    text->Draw();
    TLatex * t2;
    if(ntrkbinning) {
      t2 = new TLatex(0.1*PTMAX,0.85*(ymax-ymin)+ymin,Form("%d #leq N_{tkr}^{off} < %d",cmin[bin],cmax[bin]));
    } else {
      t2 = new TLatex(0.1*PTMAX,0.85*(ymax-ymin)+ymin,Form("%d - %d%c",cmin[bin],cmax[bin],'%'));
    }
    t2->SetTextFont(43);
    t2->SetTextSize(20);
    t2->Draw();
    TLatex * t3 = new TLatex(0.1*PTMAX,0.80*(ymax-ymin)+ymin,Form("%03.1f < #eta < %03.1f",EtaMin,EtaMax));
    t3->SetTextFont(43);
    t3->SetTextSize(20);
    t3->Draw();
    TDirectory * save = gDirectory;
    toutsubsubsub->cd();
    h->Write();
    g->Write();
    gA->Write();
    gB->Write();
    c->Write();
    save->cd();

    c->Print(Form("%s/%s.pdf",FigSubSubDir.data(), cname.data()),"pdf");
  }
  fout = fopen(Form("%s/data/%s.dat",FigSubSubDir.data(),cname.data()),"w");
  for(int i = 0; i<g->GetN(); i++){
    fprintf(fout,"%5.3f\t%9.7f\t%9.7f\n",g->GetX()[i],g->GetY()[i],g->GetEY()[i]);
  }
  fclose(fout);

  fout = fopen(Form("%s/data/%s_A.dat",FigSubSubDir.data(),cname.data()),"w");
  for(int i = 0; i<gA->GetN(); i++){
    fprintf(fout,"%5.3f\t%9.7f\t%9.7f\n",gA->GetX()[i],gA->GetY()[i],gA->GetEY()[i]);
  }
  fclose(fout);

  fout = fopen(Form("%s/data/%s_B.dat",FigSubSubDir.data(),cname.data()),"w");
  for(int i = 0; i<gB->GetN(); i++){
    fprintf(fout,"%5.3f\t%9.7f\t%9.7f\n",gB->GetX()[i],gB->GetY()[i],gB->GetEY()[i]);
  }

  fclose(fout);

 
}
void GetVN(string rootfile = "../MH.root", string name="N2SUB3",  double mineta = -0.8, double maxeta = 0.8, bool decor = false, int selbin = -1,
	   double ptmax = 12, double vnmin=-100, double vnmax=-100, double vnintmin=-100, double vnintmax=-100){
  TStopwatch * timer = new TStopwatch();
  bool found = false;
  Decor = decor;
  PTMAX=ptmax;
  VNMIN=vnmin;
  VNMAX=vnmax;
  VNINTMIN=vnintmin;
  VNINTMAX=vnintmax;
  string nlabel = name;
  if(name.find("SUB2")!=std::string::npos) Decor = false;
  if(name.find("N1MC")!=std::string::npos) Decor = false;
  if(name.find("N523")!=std::string::npos) Decor = false;
  if(name.find("N42")!=std::string::npos) Decor = false;
  if(name.find("N62")!=std::string::npos) Decor = false;
  if(name.find("N63")!=std::string::npos) Decor = false;
  if(Decor) nlabel+="_decor";
  rootFile = rootfile;
  SetTracking();
  tag = rootfile.substr(rootfile.find("/")+1,rootfile.find(".root")-rootfile.find("/")-1);
  string outname = tag+"_hists.root";
  tout = new TFile(outname.data(),"UPDATE");
  TGraphErrors * gint[cbins];
  TGraphErrors * gintA[cbins];
  TGraphErrors * gintB[cbins];
  double x[12];
  double y[12];
  double ey[12];
  for(int i = 0; i<12; i++) x[i]=-2.2+0.4*i;
  for(int i = 0; i<cbins; i++) {
    gint[i] = new TGraphErrors(12,x,y,0,ey);
    gintA[i] = new TGraphErrors(12,x,y,0,ey);
    gintB[i] = new TGraphErrors(12,x,y,0,ey);
    gint[i]->SetMarkerStyle(20);
    gintA[i]->SetMarkerStyle(24);
    gintB[i]->SetMarkerStyle(24);
    gintA[i]->SetMarkerColor(kRed);
    gintB[i]->SetMarkerColor(kBlue);
    gintA[i]->SetLineColor(kRed);
    gintB[i]->SetLineColor(kBlue);
    gint[i]->SetName(Form("sum_%s",nlabel.data()));
    gintA[i]->SetName(Form("A_%s",nlabel.data()));
    gintB[i]->SetName(Form("B_%s",nlabel.data()));
    gint[i]->SetTitle(Form("sum_%s",nlabel.data()));
    gintA[i]->SetTitle(Form("A_%s",nlabel.data()));
    gintB[i]->SetTitle(Form("B_%s",nlabel.data()));
  }

  centRef = new TH1I(Form("centRef_%s",nlabel.data()),Form("centRef_%s",nlabel.data()),ncentbins,centRefBins);
  EtaMin = mineta;
  EtaMax = maxeta;
  stag = "_"+tag;
  if(tag=="") stag = "";
  isTight   = false;
  isNominal = true;
  isWide    = false;
  isNarrow  = false;
  isLoose   = false;

  int en = 0;
  for(int indx = 0; indx<LAST; ++indx){
    if(ANALS[indx][0]==name) {
      found = true;
      en = indx;
      break;
    }
  }
  if(!found) {
    cout<<"Failed to locate analysis type"<<endl;
    return;
  }
  FILE * ftest;
  FigDir = Form("figures%s",stag.data());
  if((ftest=fopen(FigDir.data(),"r"))!=NULL) {
    //cout<<"Output directory "<<FigDir.data()<<" exists."<<endl;
    fclose(ftest);
  } else {
    system(Form("mkdir %s",FigDir.data()));
  }
  FigSubDir = FigDir+"/"+name.data();
 
  if((ftest=fopen(FigSubDir.data(),"r"))==NULL) {
    system(Form("mkdir %s",FigSubDir.data()));

  } else {
    cout<<"Directory "<<FigSubDir.data()<<" exists.  Will overwrite."<<endl;
    fclose(ftest);
  }
    toutsub = tout->mkdir(name.data());
    if(toutsub==0) toutsub=(TDirectory *) tout->Get(name.data());
  TCanvas * ceta[cbins];
  timer->Start();
  toutsubsub = toutsub->mkdir(Form("%03.1f_%03.1f",EtaMin,EtaMax));
  if(toutsubsub==0) toutsubsub=(TDirectory *) toutsub->Get(Form("%03.1f_%03.1f",EtaMin,EtaMax));
  FigSubSubDir = FigSubDir+Form("/eta_%03.1f_%03.1f",EtaMin,EtaMax);
  if(Decor) FigSubSubDir+="_decor";
  if((ftest=fopen(FigSubSubDir.data(),"r"))==NULL) {
    system(Form("mkdir %s",FigSubSubDir.data()));
    system(Form("mkdir %s/data",FigSubSubDir.data()));
    system(Form("touch %s/data/integral.dat",FigSubSubDir.data()));
    soutint = Form("%s/data/integral.dat",FigSubSubDir.data());
  } else {
    soutint = Form("%s/data/integral.dat",FigSubSubDir.data());
    fclose(ftest);
  }

  for(int bin = 0; bin<cbins; bin++) {
    timer->Stop();
    if(selbin>=0 && bin!=selbin) continue;
    toutsubsubsub = toutsubsub->mkdir(Form("%d_%d",(int) (cmin[bin]),(int)(cmax[bin])));
    if(toutsubsubsub==0) toutsubsubsub=(TDirectory *) toutsubsub->Get(Form("%d_%d",(int) (cmin[bin]),(int)(cmax[bin])));
    cout<<"toutsubsubsub make: "<<toutsubsubsub<<endl;
    int minb = rcnt->FindBin(cmin[bin]);
    int maxb = rcnt->FindBin(cmax[bin])-1;
    if(maxb<minb) maxb=minb;
    int cnt = rcnt->Integral(minb,maxb);
    cout<<"time: "<<timer->CpuTime()<<"\t"<<cmin[bin]<<"\t"<<cmax[bin]<<"\t"<<cnt<<endl;
    timer->ResetCpuTime();
    timer->Start();
    if(cnt<5000) continue;
    //pt distribution
    GetVNCreate(en,bin,gint[bin],gintA[bin],gintB[bin]);
    //eta distribution
    string FigEtaSubDir = FigSubDir;
    FigEtaSubDir+="/EtaDistributions";
    if(Decor) FigEtaSubDir+="_decor";
    if((ftest=fopen(FigEtaSubDir.data(),"r"))==NULL) {
      system(Form("mkdir %s",FigEtaSubDir.data()));
      system(Form("mkdir %s/data",FigEtaSubDir.data()));
    } else {
      fclose(ftest);
    }
    
    ceta[bin] = new TCanvas(Form("EtaInt_%s_%d_%d",nlabel.data(),cmin[bin],cmax[bin]),Form("EtaInt_%s_%d_%d",nlabel.data(),cmin[bin],cmax[bin]),800,500);
    double xmin,xmax,ymin,ymax;
    double xminA,xmaxA,yminA,ymaxA;
    double xminB,xmaxB,yminB,ymaxB;
    string nl2 = ANALS[en][0];
    nl2+=" ("+to_string(cmin[bin])+"-"+to_string(cmax[bin]);
    if(!ntrkbinning) nl2+="%";

    nl2+=")";
    string nl3 = ANALS[en][1];
    nl3+=" ("+to_string(cmin[bin])+"-"+to_string(cmax[bin]);
    if(!ntrkbinning) nl3+="%";

    nl3+=")";
    
    TH1D * heta = new TH1D(Form("heta_%s",nl2.data()),Form("heta_%s",nl2.data()),100,-2.5,2.5);
    gint[bin]->ComputeRange(xmin,ymin,xmax,ymax);
    gintA[bin]->ComputeRange(xminA,yminA,xmaxA,ymaxA);
    gintB[bin]->ComputeRange(xminB,yminB,xmaxB,ymaxB);
    ymin = plotmin(min(ymin,yminA));
    if(ymin<-0.04) ymin=-0.04;
    ymax = plotmax(max(ymax,ymaxA));

    heta->SetMaximum(ymax);
    heta->SetMinimum(ymin);
    if(VNINTMIN>-10) heta->SetMinimum(VNINTMIN);
    if(VNINTMAX>-10) heta->SetMaximum(VNINTMAX);
    heta->SetXTitle("#eta");
    heta->SetYTitle(ANALS[en][1].data());
    heta->Draw();
    if(strncmp(gint[bin]->GetTitle(),"NOGOOD",6)!=0) gint[bin]->Draw("p");
    if(strncmp(gintA[bin]->GetTitle(),"NOGOOD",6)!=0) gintA[bin]->Draw("p");
    if(strncmp(gintB[bin]->GetTitle(),"NOGOOD",6)!=0) gintB[bin]->Draw("p");
    if(strncmp(gint[bin]->GetTitle(),"NOGOOD",6)!=0) gint[bin]->Draw("p");
    TLegend * leg2 = new TLegend(0.2,0.2,0.4,0.35);
    leg2->SetTextFont(43);
    leg2->SetTextSize(20);
    leg2->SetFillColor(kWhite);
    leg2->SetBorderSize(0);
    if(strncmp(gint[bin]->GetTitle(),"Graph",5)!=0) {
      if(strncmp(gint[bin]->GetTitle(),"NOGOOD",6)!=0) leg2->AddEntry(gint[bin],gint[bin]->GetTitle(),"lp");
    } else {
      if(strncmp(gint[bin]->GetTitle(),"NOGOOD",6)!=0)leg2->AddEntry(gint[bin],"Adopted","lp");
    }
    if(strncmp(gintA[bin]->GetTitle(),"Graph",5)!=0) {
      if(strncmp(gintA[bin]->GetTitle(),"NOGOOD",6)!=0) leg2->AddEntry(gintA[bin],gintA[bin]->GetTitle(),"lp");
    } else {
      if(strncmp(gintA[bin]->GetTitle(),"NOGOOD",6)!=0) leg2->AddEntry(gintA[bin],"A side","lp");
    }
    if(strncmp(gintB[bin]->GetTitle(),"Graph",5)!=0) {
      if(strncmp(gintB[bin]->GetTitle(),"NOGOOD",6)!=0) leg2->AddEntry(gintB[bin],gintB[bin]->GetTitle(),"lp");
    } else {
      if(strncmp(gintB[bin]->GetTitle(),"NOGOOD",6)!=0) leg2->AddEntry(gintB[bin],"B side","lp");
    }


    leg2->Draw();
    TLatex * tl = new TLatex( -2,0.8*(ymax-ymin)+ymin,nl3.data());
    tl->Draw();
    if(ANALS[en][2]!="") {
      string tmp = ANALS[en][2];
      if(Decor) tmp+=" (EP Decorrelation corrected)";
      TLatex * tl2 = new TLatex( -2,0.75*(ymax-ymin)+ymin,tmp.data());
      tl2->SetTextFont(43);
      tl2->SetTextSize(16);
      tl2->Draw();
    }
    TDirectory * save = gDirectory;
    cout<<"toutsubsubsub: "<<toutsubsubsub<<endl;
    toutsubsubsub->cd();
    cout<<"heta: "<<heta<<endl;
    heta->Write();
    gint[bin]->Write();
    gintA[bin]->Write();
    gintB[bin]->Write();
    ceta[bin]->Write();
    save->cd();
    ceta[bin]->Print(Form("%s/%s.pdf",FigEtaSubDir.data(),ceta[bin]->GetName()),"pdf");

    // FILE * fint = fopen(Form("%s/data/%s.dat",FigEtaSubDir.data(),ceta[bin]->GetName()),"w");
    // for(int i = 0; i<gint[bin]->GetN(); i++) {
    //   fprintf(fint,"%5.1f\t%10.6f\t%10.6f\n",gint[bin]->GetX()[i],gint[bin]->GetY()[i],gint[bin]->GetEY()[i]);
    // }
    }
}
