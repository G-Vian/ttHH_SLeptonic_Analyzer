#ifndef PARAMETERS_H
#define PARAMETERS_H

//comment or uncomment this
//#define DEBUG_MODE

// needed for easylogging, which looks for NDEBUG
#ifndef DEBUG_MODE
#define NDEBUG
#endif

// std library
#include <assert.h>
#include <iostream>
#include <map>
#include <string>
#include <array>

// This is not C++11 safe, we need to run gccxml which does not support it
#include <unordered_map>

#include <assert.h>
#include <algorithm>
#include <bitset>
#include <chrono>
#include <limits>
#include <vector>

// ROOT
#include "Math/AllIntegrationTypes.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
#include "Math/GSLMCIntegrator.h"
#include "Math/IOptions.h"
#include "Math/IntegratorOptions.h"
#include "Math/Minimizer.h"
#include "Math/Math.h"
#include "Math/ProbFuncMathCore.h"
#include "TF1.h"
#include "TF2.h"
#include "TH3D.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TRandom3.h"
#include "TVector3.h"

//#include "TTH/MEIntegratorStandalone/interface/easylogging++.h"

#define LOG_LEVEL 0

#define ERROR 0
#define INFO 1
#define DEBUG 2
#define VLOG_IS_ON(x) false
#define LOG(x) if (LOG_LEVEL >= x) cout << "L" << x << " "
#define VLOG(x) if (LOG_LEVEL >= x) cout << "L" << x << " "
#define DVLOG(x) if (LOG_LEVEL >= x) cout << "L" << x << " "
typedef TLorentzVector LV;
using namespace std;

using namespace std::chrono;

namespace MEM {

int eta_to_bin(const double&, bool = false);
double deltaR(const LV&, const LV&);

bool descending(double, double);

std::vector<std::size_t> get_sorted_indexes(const std::vector<double>&,
                                            const double&);
bool is_in(const vector<std::size_t>&, const std::size_t&);

const double PI = 3.14159265359;
const double MTOP = 174.3;
const double MTOP2 = MTOP * MTOP;
const double MTOP4 = MTOP2 * MTOP2;
const double GTOP = 2.0;
const double MB = 4.8;
const double MB2 = MB * MB;
const double MUB = MB2 / MTOP2;
const double MQ = 0.;
const double ML = 0.;
const double MW = 80.19;
const double MW2 = MW * MW;
const double GW = 2.08;
const double DMT2 = (MTOP * MTOP - MB * MB - MW * MW) * 0.5;
const double MH = 125.;
const double MH2 = MH * MH;
const double PSHBB = 1 - 4 * MB2 / MH2;
const double GH = 0.00407;
const double DMH2 = (MH * MH - 2 * MB * MB) * 0.5;
const double DMW2 = (MW * MW) * 0.5;
const double GFERMI = 1.166e-05;
const double GEWK2 = GFERMI / sqrt(2) * 8 * MW2;
const double GEWK4 = GEWK2 * GEWK2;
const double YB = MB * sqrt(sqrt(2) * GFERMI);
const double YB2 = YB * YB;
const double BWTOP = PI / MTOP / GTOP;
const double BWH = PI / MH / GH;

const double TF_Q_param[2][5] = {
    {0.00e+00, 1.00e+00, 0.00e+00, 1.56e+00, 0.00e+00},
    {0.00e+00, 1.00e+00, 1.30e-01, 1.52e+00, 0.00e+00}};
const double TF_B_param[2][11] = {
    {-3.60e+00, 1.00e+00, 0.00e+00, 0.99e+00, 5.70e+00, -3.30e+00, 0.94e+00,
     0.16e+00, 1.70e+00, 6.60e+00, 0.65e+00},
    {-4.30e+00, 0.98e+00, 0.00e+00, 1.90e+00, 6.00e+00, 0.91e+01, 0.87e+00,
     0.23e+00, 1.10e+00, 0.00e+00, 0.65e+00},
};
const double TF_MET_param[3] = {30., 30., 0.};
//mu, sigma and lower cutoff for log-normal Sudakov
const double TF_RECOIL_param[3] = {4.1, 1.35, 9999.0};
const double TF_ACC_param[3] = {2.5, 30.};

const double BTAG_Q_param[2][2] = {{0.98, 0.02}, {0.98, 0.02}};
const double BTAG_C_param[2][2] = {{0.80, 0.20}, {0.80, 0.20}};
const double BTAG_B_param[2][2] = {{0.30, 0.70}, {0.30, 0.70}};

// int getEtaBin(double);

enum DebugVerbosity {
  output = 1,
  input = 2,
  init = 4,
  init_more = 8,
  event = 16,
  integration = 32
};

namespace TFType {
enum TFType {
  bReco = 0,
  qReco = 1,
  bLost = 2,
  qLost = 3,
  muReco = 4,
  elReco = 5,
  MET = 6,
  Recoil = 7,
  Unknown = 8
};
}

namespace DistributionType {
enum DistributionType {
  csv_b = 0,
  csv_c = 1,
  csv_l = 2,
  csv_s = 3,
  csv_u = 4,
  csv_g = 5,
  csv_b_t = 6,
  csv_b_g = 7,
  csv_c_t = 8,
  csv_c_g = 9,
  csv_1b = 10,
  csv_2b = 11,
  csv_1c = 12,
  csv_2c = 13,
  csv_pu = 14,
  csv_ud = 15,
  csv_b_dR_0p0_1p0 = 16,
  csv_b_dR_1p0_2p0 = 17,
  csv_b_dR_2p0_Inf = 18,
  csv_1b_dR_0p0_1p0 = 19,
  csv_1b_dR_1p0_2p0 = 20,
  csv_1b_dR_2p0_Inf = 21,
  csv_2b_dR_0p0_1p0 = 22,
  csv_2b_dR_1p0_2p0 = 23,
  csv_2b_dR_2p0_Inf = 24,
  csv_c_dR_0p0_1p0 = 25,
  csv_c_dR_1p0_2p0 = 26,
  csv_c_dR_2p0_Inf = 27,
  csv_1c_dR_0p0_1p0 = 28,
  csv_1c_dR_1p0_2p0 = 29,
  csv_1c_dR_2p0_Inf = 30,
  csv_2c_dR_0p0_1p0 = 31,
  csv_2c_dR_1p0_2p0 = 32,
  csv_2c_dR_2p0_Inf = 33,
  csv_pu_dR_0p0_1p0 = 34,
  csv_pu_dR_1p0_2p0 = 35,
  csv_pu_dR_2p0_Inf = 18,
  csv_s_dR_0p0_1p0 = 37,
  csv_s_dR_1p0_2p0 = 38,
  csv_s_dR_2p0_Inf = 39,
  csv_ud_dR_0p0_1p0 = 40,
  csv_ud_dR_1p0_2p0 = 41,
  csv_ud_dR_2p0_Inf = 42,
  csv_g_dR_0p0_1p0 = 43,
  csv_g_dR_1p0_2p0 = 44,
  csv_g_dR_2p0_Inf = 45,
  csv_l_dR_0p0_1p0 = 46,
  csv_l_dR_1p0_2p0 = 47,
  csv_l_dR_2p0_Inf = 48,
  Unknown = 49
};
}

namespace TFMethod {
enum TFMethod { Builtin = 0, External = 1, Unknown = 2 };
}

bool isQuark(const TFType::TFType&);
bool isNeutrino(const TFType::TFType&);
bool isLepton(const TFType::TFType&);
double Chi2Corr(const double&, const double&, const double&, const double&,
                const double&);
double Chi2(const double&, const double&, const double&);

double transfer_function(double*, double*, const TFType::TFType&, int&,
                         const double&, const int&);

double transfer_function_smear(double*, double*);

namespace ObjectType {
enum ObjectType { Jet = 0, Lepton = 1, MET = 2, Recoil = 3, Unknown = 4 };
}

namespace Observable {
enum Observable {
  E_LOW_Q = 0,
  E_HIGH_Q = 1,
  E_LOW_B = 2,
  E_HIGH_B = 3,
  BTAG = 4,
  CHARGE = 5,
  PDGID = 6,
  CSV = 7,
  BTAGPROB = 8,
  MCMATCH = 9,
  IGNORE_FOR_RND = 10
};
}

class ObsHash {
 public:
  std::size_t operator()(const Observable::Observable& s) const {
    const std::size_t h1 = static_cast<std::size_t>(s);
    return h1;
  }
};

class ObsEqual {
 public:
  bool operator()(const Observable::Observable& a,
                  const Observable::Observable& b) const {
    return static_cast<std::size_t>(a) == static_cast<std::size_t>(b);
  }
};

class TFTypeHash {
 public:
  std::size_t operator()(const TFType::TFType& s) const {
    const std::size_t h1 = static_cast<std::size_t>(s);
    return h1;
  }
};

class TFTypeEqual {
 public:
  bool operator()(const TFType::TFType& a, const TFType::TFType& b) const {
    return static_cast<std::size_t>(a) == static_cast<std::size_t>(b);
  }
};

class Object {
 public:
  Object(const LV&, const ObjectType::ObjectType&,
         DistributionType::DistributionType =
             DistributionType::DistributionType::Unknown,
         DistributionType::DistributionType =
             DistributionType::DistributionType::Unknown);
  Object();
  ~Object();
  LV p4() const;
  void setp4(const LV&);
  ObjectType::ObjectType type() const;
  DistributionType::DistributionType distribution_type() const;
  DistributionType::DistributionType distribution_type_bkp() const;
  double getObs(const Observable::Observable&) const;
  TF1* getTransferFunction(TFType::TFType) const;
  std::size_t getNumTransferFunctions() const;
  bool isSet(const Observable::Observable&) const;
  void addObs(const Observable::Observable&, const double&);
  void addTransferFunction(const TFType::TFType&, TF1*);
  void print(ostream& os) const;
  vector<double> p4_variations;
  
  const static int NUM_TF_PARS = 12;
  std::array<double, 12> tf_b_parameters;
  std::array<double, 12> tf_l_parameters;
  
 private:
  LV p;
  ObjectType::ObjectType t;
  DistributionType::DistributionType dt;
  DistributionType::DistributionType dt_bkp;
  std::unordered_map<const Observable::Observable, double, ObsHash, ObsEqual>
      obs;
  std::unordered_map<const TFType::TFType, TF1*, TFTypeHash, TFTypeEqual>
      transfer_funcs;

};
pair<double, double> get_support(double*, TFType::TFType, double, int,
                                 Object* = nullptr, bool eval_compiled=false);

namespace PSVar {
enum PSVar {
  E_q1 = 0,
  cos_q1 = 1,
  phi_q1 = 2,
  E_qbar1 = 3,
  cos_qbar1 = 4,
  phi_qbar1 = 5,
  E_b1 = 6,
  cos_b1 = 7,
  phi_b1 = 8,
  E_q2 = 9,
  cos_q2 = 10,
  phi_q2 = 11,
  E_qbar2 = 12,
  cos_qbar2 = 13,
  phi_qbar2 = 14,
  E_b2 = 15,
  cos_b2 = 16,
  phi_b2 = 17,
  E_b = 18,
  cos_b = 19,
  phi_b = 20,
  E_bbar = 21,
  cos_bbar = 22,
  phi_bbar = 23,
  P_t = 24,
  cos_t = 25,
  phi_t = 26,
  P_tbar = 27,
  cos_tbar = 28,
  phi_tbar = 29,
  P_h = 30,
  cos_h = 31,
  phi_h = 32,
  Px_h = 33,
  Py_h = 34,
  Pz_h = 35,
  E_rad = 36,
  cos_rad = 37,
  phi_rad = 38
};
}

namespace PSPart {
enum PSPart {
  // first W boson, hadronic in case of lepton-hadron (LH) decay of ttbar
  q1 = 0,
  qbar1 = 1,
  b1 = 2,

  // second W boson, leptonic in case of LH decay of ttbar
  q2 = 3,
  qbar2 = 4,
  b2 = 5,

  // additional b quarks (H->bb)
  b = 6,
  bbar = 7,

  // top quarks
  t = 8,
  tbar = 9,

  // higgs
  h = 10,

  // additional radiation
  gluon_rad = 11
};
}

class PSVarHash {
 public:
  std::size_t operator()(const PSVar::PSVar& s) const {
    std::size_t h1 = std::hash<std::size_t>()(static_cast<std::size_t>(s));
    return h1;
  }
};

class PSVarEqual {
 public:
  typedef PSVar::PSVar value_type;
  bool operator()(const PSVar::PSVar& a, const PSVar::PSVar& b) const {
    return static_cast<std::size_t>(a) == static_cast<std::size_t>(b);
  }
};

class PSPartHash {
 public:
  std::size_t operator()(PSPart::PSPart const& s) const {
    //std::size_t h1 = std::hash<std::size_t>()(static_cast<std::size_t>(s));
    const std::size_t h1 = static_cast<std::size_t>(s);
    return h1;
  }
};

class PSPartEqual {
 public:
  bool operator()(const PSPart::PSPart& a, const PSPart::PSPart& b) const {
    return static_cast<std::size_t>(a) == static_cast<std::size_t>(b);
  }
};

struct GenPart {
  GenPart() {
    lv = LV();
    type = TFType::Unknown;
  }
  GenPart(const LV& a, const TFType::TFType& b, const int c) {
    lv = a;
    type = b;
    charge = c;
  }
  LV lv;
  TFType::TFType type;
  int charge;
};

typedef std::unordered_map<MEM::PSPart::PSPart, MEM::GenPart, MEM::PSPartHash,
                           MEM::PSPartEqual>
    PSMap;

class PS {
 public:
  PS(std::size_t = 0);
  ~PS();
  PSMap::const_iterator begin() const;
  PSMap::const_iterator end() const;
  LV lv(const PSPart::PSPart&) const;
  int charge(const PSPart::PSPart&) const;
  TFType::TFType type(const PSPart::PSPart&) const;
  void set(const PSPart::PSPart&, const GenPart&);
  void print(ostream&) const;
  PSMap val;

 private:
  std::size_t dim;
};

namespace Hypothesis {
enum Hypothesis { TTH = 0, TTBB = 1, Undefined = 2 };
}

namespace Process {
enum Process { TTH = 0, TTBB = 1, TTHj = 2, TTBBj = 3, Undefined = 4 };
}

namespace PermConstants {
enum PermConstants {
  btag_TTBB = 0,
  btag_TTCC = 1,
  btag_TTJJ = 2,
  VarTransf = 4
};
}

namespace FinalState {
enum FinalState { HH = 0, LH = 1, LL = 2, TTH = 3, Undefined = 4 };
}

namespace Assumption {
enum Assumption {
  ZeroQuarkLost = 0,
  OneQuarkLost = 1,
  TwoQuarkLost = 2,
  ThreeQuarkLost = 3,
  FourQuarkLost = 4,
  FiveQuarkLost = 5
};
}

namespace Permutations {
enum Permutations {
  BTagged = 0,
  QUntagged,
  QQbarSymmetry,
  BBbarSymmetry,
  QQbarBBbarSymmetry,
  HEPTopTagged,
  HEPTopTaggedNoPrefix,
  HiggsTagged,
  FirstRankedByBTAG,
  FirstTwoRankedByBTAG,
  FirstThreeRankedByBTAG
};
}

namespace IntegrandType {
enum IntegrandType {
  Constant = 1,
  Jacobian = 2,
  Transfer = 4,
  ScattAmpl = 8,
  DecayAmpl = 16,
  PDF = 32,
  Sudakov = 64,
  Recoil = 128,
  SmearJets = 256,
  SmearMET = 512,
  AdditionalRadiation = 1024,
};
}
  
namespace IntegratorType {
  enum IntegratorType {
    Vegas_GSL = 1,
    Vegas = 2,
    Suave = 4,
  };
}

struct CompPerm {
  CompPerm(int order = 0) { highpt_first = order; }
  CompPerm& operator=(const CompPerm& cmp) {
    highpt_first = cmp.highpt_first;
    return *this;
  }
  bool operator()(int a, int b) {
    if (highpt_first)
      return a < b;
    else
      return a > b;
  }
  int highpt_first;
};

struct MEMConfig {
  MEMConfig(
      int = 4000,         // num of int points
      double = 0.0,    // absolute tol. // has no effect on integration
      double = 0.01,     // relative tol.
      int = 0,            // two-stage integration
      int = 4,            // number of 2nd-stage iterations
      int = 0,            // int_code
      int = 0,            // =0 <=> Int{ Perm }; =1 <=> Perm{ Int }
      double = 13000.,    // c.o.m. energy
      double = 1000.,     // max energy for integration over momenta
      string = "cteq66",  // PDF set
      double = 0.998,      // light quark energy CL #DS was 0.98=2.3sigm
      double = 0.998,      // heavy quark energy CL #DS 0.9973=3sigma, 0.99994=4sigma
      double = 0.98,      // nu phi CL
      int = 0,  // tf_offscale, if ==1 skip matrix evaluation if some TF are evaluated art chi2>...
      double = 6.6,  // ... ( <=> TMath::ChisquareQuantile(0.99, 1)=6.6 )
      bool =
          false,  // restrict tf to same range used for quark energy integration
      int = 1,    // use highest pT jets for E_q/E_b,
      TFMethod::TFMethod = TFMethod::Builtin,
      int = 0,         // do minimisation instead of integration
      int = 0,         // do runtime pruning of permutations
      double = 1e-03,  // pruning accuracy
      int = 0,         // prefit
      int max_permutations = 500);

  void defaultCfg(float nCallsMultiplier = 1.0);
  void setNCalls(FinalState::FinalState, Hypothesis::Hypothesis,
                 Assumption::Assumption, int);
  int getNCalls(FinalState::FinalState, Hypothesis::Hypothesis,
                Assumption::Assumption);
  void set_tf_global(TFType::TFType type, int etabin, TF1* tf);
  void add_distribution_global(DistributionType::DistributionType type,
                               TH3D* tf);

  // optionally this can be called instead of the built-in array
  int n_max_calls;

  // "map" between an integration type and the number of function calls
  // FinalState vs Hypothesis vs Assumption
  int calls[4][2][6];

  // the VEGAS options
  double rel;
  double abs;
  int integrator_type;
  //0 - integrate on master, 1 - single child, n>1 - multiple cores via fork
  int cuba_cores;
  int two_stage;
  int niters;

  // what to include into the integrand
  int int_code;

  // sqrt of S and maximum quark energy
  double sqrts;
  double emax;

  // pdf set (to be initiated once)
  string pdfset;

  // strategy to prune permutations
  std::vector<Permutations::Permutations> perm_pruning;

  // if true, use n_max_calls instead of the built-in array
  bool is_default;

  // CL of jet and met range
  double j_range_CL;
  double b_range_CL;
  double m_range_CL;

  // flag that configures if permutation sum is done inside or outside the
  // integral
  // perm_int == 1: do_integration does \sum_perm \int
  // perm_int == 0: do_integration does \int \sum_perm
  int perm_int;

  // the number of jets for which the tf,
  // being evaluated at a too unlikely value,
  // triggers the return of a 0.
  int tf_suppress;

  // the maximum value of a chi2 in a tf evaluation
  // such that the tf is truncated
  double tf_offscale;

  // restrict the tf to be in the same range
  // used for integration over the quark energy
  bool tf_in_range;

  // use high pT jets first
  int highpt_first;

  TFMethod::TFMethod transfer_function_method;

  // do minimzation, not integration
  int do_minimize;

  // do runtime pruning of permutations
  int do_perm_filtering;

  // pruning accuracy
  double perm_filtering_rel;

  // do a pre-fit to filter permutations
  int do_prefit;

  // maximum number of permutations to consider
  int max_permutations;
  
  int num_jet_variations;

  std::map<std::pair<TFType::TFType, int>, std::array<double, Object::NUM_TF_PARS>> tf_map;

  std::map<DistributionType::DistributionType, TH3D*> btag_pdfs;
  bool save_permutations;
  
  //Perform PDF calculation using interpolation
  bool interpolate_pdf;
 
  //Evaluate a precompiled version of the TF
  bool eval_compiled_tf;

  double jet_pt_threshold = 30;
};

class MEMOutput {
 public:
  double p;
  double p2;
  double p_err;
  double chi2;
  int error_code;
  int time;
  int num_max_calls;
  int num_calls;
  float efficiency;
  int prefit_code;
  std::size_t num_perm;
  std::size_t assumption;

  size_t tf_zero;
  FinalState::FinalState final_state;
  Hypothesis::Hypothesis hypothesis;

  vector<size_t> permutations;
  vector<vector<int>> permutation_indexes;
  vector<double> permutation_sum;
  vector<vector<double>> permutation_probas;
  vector<vector<double>> permutation_probas_constants;
  vector<vector<double>> permutation_probas_transfer;
  vector<vector<double>> permutation_probas_me;
  
  //MEM gradient
  vector<double> grad;
  //variation of transfer functions
  vector<double> variated;

  void print(std::ostream& os) {
    os.precision(3);
    os << "\t**************** MEM output ****************" << endl;
    os << "\tProbability             = (" << p << " +/- " << p_err << ")" << endl;
    os << "\tMCMC integration        = " << p2 << endl;
    os.precision(2);
    os << "\tRelative precision      = " << (p_err / p) * 100 << "%" << endl;
    os.precision(3);
    for (unsigned int i=0; i < grad.size(); i++) {
      os << "\tGradient[" << i << "]             = " << grad[i] << endl;
    }
    for (unsigned int i=0; i < variated.size(); i++) {
      os << "\tVariated[" << i << "]             = " << variated[i] << endl;
    }
    os << "\tChi2                    = " << chi2 << endl;
    os << "\tFinal state             = "
       << static_cast<std::size_t>(final_state) << endl;
    os << "\tHypothesis              = " << static_cast<std::size_t>(hypothesis)
       << endl;
    os << "\tNumber of unreco's jets = " << assumption << endl;
    os << "\tNumber of permutations  = " << num_perm << endl;
    os << "\tTotal number of calls   = " << num_calls << endl;
    os << "\tMaximum number of calls = " << num_max_calls << endl;
    os << "\tPhase-space efficiency  = " << efficiency * 100 << "%" << endl;
    os << "\tError code              = " << error_code << endl;
    os << "\tTF = 0                  = " << tf_zero << endl;
    os << "\tJob done in..............." << time * 0.001 << " seconds" << endl;
    os << "\t********************************************" << endl;
    os.precision(8);
  }
  void print_short(std::ostream& os) {
    os.precision(3);
    os << "\t**************** MEM output ****************" << endl;
    os << "\tProbability             = (" << p << " +/- " << p_err << ")" << endl;
    os << "\tMCMC integration        = " << p2 << endl;
    os.precision(2);
    os << "\tRelative precision      = " << (p_err / p) * 100 << "%" << endl;
    os.precision(3);
    for (unsigned int i=0; i < 2; i++) { //prints only first 2 gradients
      os << "\tGradient[" << i << "]             = " << grad[i] << endl;
    }
    for (unsigned int i=0; i < 4; i++) { //prints only first 4 variations
      os << "\tVariated[" << i << "]             = " << variated[i] << endl;
    }
    os << "\tChi2                    = " << chi2 << endl;
    os << "\tFinal state             = "
       << static_cast<std::size_t>(final_state) << endl;
    os << "\tHypothesis              = " << static_cast<std::size_t>(hypothesis)
       << endl;
    os << "\tNumber of unreco's jets = " << assumption << endl;
    os << "\tNumber of permutations  = " << num_perm << endl;
    os << "\tTotal number of calls   = " << num_calls << endl;
    os << "\tMaximum number of calls = " << num_max_calls << endl;
    os << "\tPhase-space efficiency  = " << efficiency * 100 << "%" << endl;
    os << "\tError code              = " << error_code << endl;
    os << "\tTF = 0                  = " << tf_zero << endl;
    os << "\tJob done in..............." << time * 0.001 << " seconds" << endl;
    os << "\t********************************************" << endl;
    os.precision(8);
  }
};

double transfer_function2(MEM::Object* obj, const double* x, const TFType::TFType& type,
                          vector<double>& obj_variations, bool eval_variations);

double transfer_function_reco(double pt, const vector<double>& pt_variations, const std::array<double, MEM::Object::NUM_TF_PARS>& pars, const double* x, vector<double>& obj_variations, const bool eval_variations);

double transfer_function_lost(double pt, const std::array<double, MEM::Object::NUM_TF_PARS>& pars, const double* x);

    
// hardcode permutations to save ~400 sec in 9j category
vector<vector<int>> get_permutations(std::size_t, std::size_t, vector<std::size_t>&);
}

#endif
