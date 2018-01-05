void Fill_N112A(int anal, int bin, TH2D * qxtrk_, TH2D * qytrk_, TH2D * qcnt_, double * qx, double * qy, double * sumw){
  double a1x = qx[HFp1];
  double a1y = qy[HFp1];
  double a1w = sumw[HFp1];
  double a2x = qx[HFp2];
  double a2y = qy[HFp2];
  double a2w = sumw[HFp2];

  double b1x = qx[HFm1];
  double b1y = qy[HFm1];
  double b1w = sumw[HFm1];
  double b2x = qx[HFm2];
  double b2y = qy[HFm2];
  double b2w = sumw[HFm2];

  double c1x = qx[trackm110];
  double c1y = qy[trackm110];
  double c1w = sumw[trackm110];

  if(pow(a1x,2)+pow(a1y,2) < 1e-8) return;
  if(pow(b1x,2)+pow(b1y,2) < 1e-8) return;
  if(pow(c1x,2)+pow(c1y,2) < 1e-8) return;
  if(pow(a2x,2)+pow(a2y,2) < 1e-8) return;
  if(pow(b2x,2)+pow(b2y,2) < 1e-8) return;

  qanal[anal].qA[bin][0]->Add(qxtrk_,a1x*b2x+a1y*b2y);
  qanal[anal].qA[bin][0]->Add(qytrk_,-a1y*b2x+a1x*b2y);
  qanal[anal].qB[bin][0]->Add(qxtrk_,b1x*a2x+b1y*a2y);
  qanal[anal].qB[bin][0]->Add(qytrk_,-b1y*a2x+b1x*a2y);
  qanal[anal].wnA[bin][0]->Add(qcnt_,a1w*b2w);
  qanal[anal].wnB[bin][0]->Add(qcnt_,b1w*a2w);
  qanal[anal].qBA[bin][0]->Fill(0., a1x*b1x*b2x - a1y*b1y*b2x + a1y*b1x*b2y + a1x*b1y*b2y);
  qanal[anal].qCA[bin][0]->Fill(0., a1x*b2x*c1x + a1y*b2y*c1x - a1y*b2x*c1y + a1x*b2y*c1y); 
  qanal[anal].qCB[bin][0]->Fill(0.,b1x*c1x + b1y*c1y);
  qanal[anal].qBAcnt[bin][0]->Fill(0.,b1w*a1w*b2w);
  qanal[anal].qCAcnt[bin][0]->Fill(0.,c1w*a1w*b2w);
  qanal[anal].qCBcnt[bin][0]->Fill(0.,c1w*b1w);
  
  int j=(int)(ran->Uniform(0,9.999))+1;
  qanal[anal].qA[bin][j]->Add(qxtrk_,a1x*b2x+a1y*b2y);
  qanal[anal].qA[bin][j]->Add(qytrk_,-a1y*b2x+a1x*b2y);
  qanal[anal].qB[bin][j]->Add(qxtrk_,b1x*a2x+b1y*a2y);
  qanal[anal].qB[bin][j]->Add(qytrk_,-b1y*a2x+b1x*a2y);
  qanal[anal].wnA[bin][j]->Add(qcnt_,a1w*b2w);
  qanal[anal].wnB[bin][j]->Add(qcnt_,b1w*a2w);
  qanal[anal].qBA[bin][j]->Fill(0., a1x*b1x*b2x - a1y*b1y*b2x + a1y*b1x*b2y + a1x*b1y*b2y);
  qanal[anal].qCA[bin][j]->Fill(0., a1x*b2x*c1x + a1y*b2y*c1x - a1y*b2x*c1y + a1x*b2y*c1y); 
  qanal[anal].qCB[bin][j]->Fill(0.,b1x*c1x + b1y*c1y);

  qanal[anal].qBAcnt[bin][j]->Fill(0.,b1w*a1w*b2w);
  qanal[anal].qCAcnt[bin][j]->Fill(0.,c1w*a1w*b2w);
  qanal[anal].qCBcnt[bin][j]->Fill(0.,c1w*b1w);
}

void Fill_N112B(int anal, int bin, TH2D * qxtrk_, TH2D * qytrk_, TH2D * qcnt_, double * qx, double * qy, double * sumw){
  double a1x = qx[HFm1];
  double a1y = qy[HFm1];
  double a1w = sumw[HFm1];
  double a2x = qx[HFm2];
  double a2y = qy[HFm2];
  double a2w = sumw[HFm2];

  double b1x = qx[HFp1];
  double b1y = qy[HFp1];
  double b1w = sumw[HFp1];
  double b2x = qx[HFp2];
  double b2y = qy[HFp2];
  double b2w = sumw[HFp2];

  double c1x = qx[trackp110];
  double c1y = qy[trackp110];
  double c1w = sumw[trackp110];

  if(pow(a1x,2)+pow(a1y,2) < 1e-8) return;
  if(pow(b1x,2)+pow(b1y,2) < 1e-8) return;
  if(pow(c1x,2)+pow(c1y,2) < 1e-8) return;
  if(pow(a2x,2)+pow(a2y,2) < 1e-8) return;
  if(pow(b2x,2)+pow(b2y,2) < 1e-8) return;


  qanal[anal].qA[bin][0]->Add(qxtrk_,a1x*b2x+a1y*b2y);
  qanal[anal].qA[bin][0]->Add(qytrk_,-a1y*b2x+a1x*b2y);
  qanal[anal].qB[bin][0]->Add(qxtrk_,b1x*a2x+b1y*a2y);
  qanal[anal].qB[bin][0]->Add(qytrk_,-b1y*a2x+b1x*a2y);
  qanal[anal].wnA[bin][0]->Add(qcnt_,a1w*b2w);
  qanal[anal].wnB[bin][0]->Add(qcnt_,b1w*a2w);
  qanal[anal].qBA[bin][0]->Fill(0., a1x*b1x*b2x - a1y*b1y*b2x + a1y*b1x*b2y + a1x*b1y*b2y);
  qanal[anal].qCA[bin][0]->Fill(0., a1x*b2x*c1x + a1y*b2y*c1x - a1y*b2x*c1y + a1x*b2y*c1y); 
  qanal[anal].qCB[bin][0]->Fill(0.,b1x*c1x + b1y*c1y);
  qanal[anal].qBAcnt[bin][0]->Fill(0.,b1w*a1w*b2w);
  qanal[anal].qCAcnt[bin][0]->Fill(0.,c1w*a1w*b2w);
  qanal[anal].qCBcnt[bin][0]->Fill(0.,c1w*b1w);
  
  int j=(int)(ran->Uniform(0,9.999))+1;
  qanal[anal].qA[bin][j]->Add(qxtrk_,a1x*b2x+a1y*b2y);
  qanal[anal].qA[bin][j]->Add(qytrk_,-a1y*b2x+a1x*b2y);
  qanal[anal].qB[bin][j]->Add(qxtrk_,b1x*a2x+b1y*a2y);
  qanal[anal].qB[bin][j]->Add(qytrk_,-b1y*a2x+b1x*a2y);
  qanal[anal].wnA[bin][j]->Add(qcnt_,a1w*b2w);
  qanal[anal].wnB[bin][j]->Add(qcnt_,b1w*a2w);
  qanal[anal].qBA[bin][j]->Fill(0., a1x*b1x*b2x - a1y*b1y*b2x + a1y*b1x*b2y + a1x*b1y*b2y);
  qanal[anal].qCA[bin][j]->Fill(0., a1x*b2x*c1x + a1y*b2y*c1x - a1y*b2x*c1y + a1x*b2y*c1y); 
  qanal[anal].qCB[bin][j]->Fill(0.,b1x*c1x + b1y*c1y);

  qanal[anal].qBAcnt[bin][j]->Fill(0.,b1w*a1w*b2w);
  qanal[anal].qCAcnt[bin][j]->Fill(0.,c1w*a1w*b2w);
  qanal[anal].qCBcnt[bin][j]->Fill(0.,c1w*b1w);

}
