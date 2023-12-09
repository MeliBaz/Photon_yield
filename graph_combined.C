void graph_combined(){
    TFile *file1=TFile::Open("Photon_yield_20.root");
    TFile *file2=TFile::Open("Photon_yield_90.root");
    TFile *file3=TFile::Open("Photon_yield_140.root");   

TGraphErrors *g1=(TGraphErrors*)file1->Get("g");
TGraphErrors *g2=(TGraphErrors*)file2->Get("g");
TGraphErrors *g3=(TGraphErrors*)file3->Get("g");
TLine *v_line= new TLine(5,0,5,74);
TCanvas* c1=new TCanvas();
g1->SetLineColor(kRed);
g2->SetLineColor(kBlue);
g3->SetLineColor(kGreen);

v_line->SetLineColor(kBlack);
g1->GetXaxis()->SetLimits(0,50);
v_line->SetLineWidth(2);
v_line->SetLineStyle(kDashed);

g1->Draw("ALP");
g2->Draw("LP same");
g3->Draw("LP same");
v_line->Draw("same");

TLegend *legend = new TLegend(0.7,0.7,0.9,0.9);
legend->SetTextSize(0.04);
legend->AddEntry(g1,"20 deg","l");
legend->AddEntry(g2,"90 deg","l");
legend->AddEntry(g3,"140 deg","l");
legend->AddEntry(v_line,"5 #AA","l");
legend->Draw("same");
c1->SetGrid();
c1->Draw();
}
