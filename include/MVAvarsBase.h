#ifndef TTH_MVAVARSBASE_H
#define TTH_MVAVARSBASE_H
#include <vector>
#include <map>
#include <math.h>
#include "TLorentzVector.h"
#include "TMVA/Reader.h"
#include "TTH/CommonClassifier/interface/CommonBDTvars.h"

// class to evaluate lepton plus jets BDT set
class MVAvarsBase
{

  public:
    MVAvarsBase();
    virtual ~MVAvarsBase();

    // Call this method to return the MVa vars, provide all necessary inputs. Jet CSV should be sorted the same way as jet p4.
    // We could also write a class to contain the jet CSV and p4 information
    std::map<std::string, float> GetMVAvars(const std::vector<TLorentzVector> &selectedLeptonP4,
                      const std::vector<TLorentzVector> &selectedJetP4,
                      const std::vector<double> &selectedJetCSV,
                      const TLorentzVector &metP4);
    std::map<std::string, float> GetMVAvars(  const std::vector<TLorentzVector> &selectedLeptonP4,
                                              const std::vector<TLorentzVector> &selectedJetP4,
                                              const std::vector<double> &selectedJetCSV,
                                              const TLorentzVector &metP4,
                                              const std::vector<int> &jets_idx);


    // return the variable names and their values for the last evaluated event
    std::map<std::string, float>& GetVariables();
    float* GetAdress(std::string variablelabel){return &variableMap[variablelabel];}
    void SetWP(double WP);
    void SetLooseWP(double WPLoose);

    double GetWP(){
      return btagMcut;
    }
    virtual void FillMVAvarMap( const std::vector<TLorentzVector> &selectedLeptonP4,
                                const std::vector<TLorentzVector> &selectedJetP4,
                                const std::vector<double> &selectedJetCSV,
                                const TLorentzVector &metP4);

    virtual void FillMVAvarMap( const std::vector<TLorentzVector> &selectedLeptonP4,
                                const std::vector<TLorentzVector> &selectedJetP4,
                                const std::vector<double> &selectedJetCSV,
                                const TLorentzVector &metP4,
                                const std::vector<int> &jets_idx);

    virtual std::map<std::string, TLorentzVector> GetVectors(   const TLorentzVector &selectedLeptonP4,
                                                                const std::vector<TLorentzVector> &selectedJetP4,
                                                                const TLorentzVector &metP4,
                                                                const std::vector<int> &jets_idx);

    virtual bool SkipEvent( const std::vector<TLorentzVector> &selectedJetP4,
                            const std::vector<double> &selectedJetCSV,
                            const std::vector<int> &jets_idx);

    virtual void SetTopisleptonic(bool isit){cout << "ERROR: dont call `SetTopisleptonic()` for non MVAvarsJABDTthw-objects!" << endl;}

    float GetGlobalDefault(){return globalDefault;}
    std::vector<std::string> GetRecolabels(){return Recolabels;}

    float GetHT(const std::vector<TLorentzVector> &selectedJetP4);
    TLorentzVector GetLeptonicW(const TLorentzVector &leptonP4,
                                const TLorentzVector &metP4);

    bool JetIsCentral(const TLorentzVector &jet){return TMath::Abs(jet.Eta()) < 2.4 && jet.Pt() > 30;}
    bool JetIsSelected(const TLorentzVector &jet){return JetIsCentral(jet) || jet.Pt() > 40;}
    bool JetIsTagged(const TLorentzVector &jet, const double& jetCSV){return jetCSV > btagMcut && JetIsCentral(jet);}
    bool JetIsLooseTagged(const TLorentzVector &jet, const double& jetCSV){return jetCSV > btagLcut;}

    void ResetVariableMap();

  protected:
    std::map<std::string, float> variableMap;
    std::vector<std::string> Recolabels;

    double btagMcut = -99;
    double btagLcut = -99;
    float globalDefault = -1.5;
};
#endif
