#pragma once

#include "UHH2/core/include/Selection.h"
#include "UHH2/core/include/Event.h"

#include "UHH2/common/include/ObjectIdUtils.h"

// This file defines multiplicity selections on jets, leptons, etc
// General conventions:
//  * Events are selected if the multiplicity is between >= nmin and <= nmax, i.e. nmin and nmax are allowed values
//  * nmax = -1 means to not apply a maximum cut (to not apply nmin cut, use nmin <= 0).
//
// The modules allow two modes of operation:
//  * no id criterion is applied, so all currently available objects are counted.
//    In this mode, you might want to run an appropriate CleaningModule first to make sure only 
//    objects passing proper id / kinematic cuts are counted
//  * an id is used as argument (see ObjectIdUtils for the type of the id). In this case, only objects passing the id are counted.
//
// The constructor defaults are such that no explicit id is passed ('none'); in this case, all objects are counted,
// which corresponds to the first of the two described modes.


class NTauSelection: public uhh2::Selection {
public:
    explicit NTauSelection(int nmin, int nmax = -1, const boost::optional<TauId> & tauid = boost::none);
    virtual bool passes(const uhh2::Event & event);
private:
    int nmin, nmax;
    boost::optional<TauId> tauid;
};

class NMuonSelection: public uhh2::Selection {
public:
    explicit NMuonSelection(int nmin, int nmax = -1, const boost::optional<MuonId> & muid = boost::none);
    virtual bool passes(const uhh2::Event & event);
private:
    int nmin, nmax;
    boost::optional<MuonId> muid;
};


class NElectronSelection: public uhh2::Selection {
public:
    explicit NElectronSelection(int nmin, int nmax = -1, const boost::optional<ElectronId> & eleid = boost::none);
    virtual bool passes(const uhh2::Event & event);
private:
    int nmin, nmax;
    boost::optional<ElectronId> eleid;
};

class NJetSelection: public uhh2::Selection {
public:
    explicit NJetSelection(int nmin, int nmax = -1, const boost::optional<JetId> & jetid = boost::none);
    virtual bool passes(const uhh2::Event & event);
private:
    int nmin, nmax;
    boost::optional<JetId> jetid;
};

class NTopJetSelection: public uhh2::Selection {
public:
    explicit NTopJetSelection(int nmin, int nmax = -1, const boost::optional<TopJetId> & topjetid = boost::none);
    virtual bool passes(const uhh2::Event & event);
private:
    int nmin, nmax;
    boost::optional<TopJetId> topjetid;
};
