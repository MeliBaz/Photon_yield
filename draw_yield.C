#if defined(__ACLIC__)
#include "../../prttools/PrtTools.h"
#else
R__LOAD_LIBRARY(../build/libPrt.so)
#endif

void draw_yield(TString infile = "../build/hits.root") {

  PrtTools t(infile);
   double theta = t.run()->getTheta();
   double roughness=t.run()->getTest1();

 
 TH1F *hist=new TH1F("hist","hist:photon yield:Entries", 120,0, 120);

  while (t.next() && t.i() < 50000) {
   hist->Fill(t.event()->getHits().size());
  


    for (auto hit : t.event()->getHits()) {
      int ch = hit.getChannel();
      int pmt = hit.getPmt();
      int pix = hit.getPixel();

      double time = hit.getLeadTime();

      // if (t.pid() == 4)
	t.fill_digi(pmt, pix);

    }
  }

  auto r = hist->Fit("gaus", "S");
  double mvalue = r->Parameter(1);
  double mean_error = r->ParError(1);
  t.add_canvas("photon_yield");
  hist->Draw();
  auto cdigi = t.draw_digi();
  t.add_canvas(cdigi);
  t.save_canvas("data/drawHP", 0);

  t.write_string("digi.csv", t.pix_digi("m,p,v\n"));  
  
  TFile *output_data = new TFile(Form("roughness_%.1f.root", roughness), "recreate");
  TTree *otree = new TTree("roughness", "roughness");
  otree->Branch("roughness", &roughness);
  otree->Branch("mvalue", &mvalue);
  otree->Branch("mean_error", &mean_error);
  otree->Fill();
  output_data->Write();

 


}
