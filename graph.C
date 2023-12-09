void graph(TString input=" "){
Double_t roughness,mvalue,mean_error;
TChain ch("roughness");
ch.Add(input);
ch.SetBranchAddress("roughness", &roughness);
ch.SetBranchAddress("mvalue", &mvalue);
ch.SetBranchAddress("mean_error", &mean_error);
int numberOfEntries=ch.GetEntries();
TGraphErrors* g = new TGraphErrors();
for (Int_t i = 0; i < ch.GetEntries(); i++)
{ 
    ch.GetEntry(i);
    g->SetPoint(i,roughness,mvalue);
    g->SetPointError(i,0,mean_error);
}
    g->Sort();
   TCanvas *c1=new TCanvas();
   g->SetTitle("Photon yield;Roughness [#AA];Number of photons [#]");
   g->SetMinimum(0);
   g->SetMarkerColor(1);
   g->SetMarkerStyle(5);
   g->Draw("ALP");
   TFile *output_data = new TFile("Photon_yield_140.root", "recreate");
   g->SetName("g");
   g->Write();
   output_data->Write();
   c1->SetGrid();
   c1->Draw();
}