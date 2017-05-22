//  MABE is a product of The Hintze Lab @ MSU
//     for general research information:
//         hintzelab.msu.edu
//     for MABE documentation:
//         github.com/ahnt/MABE/wiki
//
//  Copyright (c) 2015 Michigan State University. All rights reserved.
//     to view the full license, visit:
//         github.com/ahnt/MABE/wiki/License

#ifndef __BasicMarkovBrainTemplate__IPDBrain__
#define __BasicMarkovBrainTemplate__IPDBrain__

#include <math.h>
#include <memory>
#include <iostream>
#include <set>
#include <vector>

#include "../../Genome/AbstractGenome.h"

#include "../../Utilities/Random.h"

#include "../AbstractBrain.h"


using namespace std;

class IPDBrain: public AbstractBrain {
public:

	static shared_ptr<ParameterLink<string>> availableStrategiesPL;
	static shared_ptr<ParameterLink<string>> genomeNamePL;

	string genomeName;

	vector<string> availableStrategies;
	string strategy;
	vector<double> movesSelf;
	vector<double> movesOther;
	vector<double> internalValues; // can be used by individual strategies as needed

	IPDBrain() = delete;

	IPDBrain(int _nrInNodes, int _nrOutNodes, shared_ptr<ParametersTable> _PT = nullptr);

	virtual ~IPDBrain() = default;

	virtual void update() override;

	// Make a brain like the brain that called this function, using genomes and initalizing other elements.
	virtual shared_ptr<AbstractBrain> makeBrain(unordered_map<string, shared_ptr<AbstractGenome>>& _genomes) override;

	virtual shared_ptr<AbstractBrain> makeBrainFromValues(vector<double> values);

	virtual string description() override;
	virtual DataMap getStats(string& prefix) override;

	virtual void resetBrain() override;
	//virtual void resetOutputs() override;

	virtual void initalizeGenome(unordered_map<string, shared_ptr<AbstractGenome>>& _genomes);

	virtual unordered_set<string> requiredGenomes() override {
		return { genomeName };
	}
};

inline shared_ptr<AbstractBrain> IPDBrain_brainFactory(int ins, int outs, shared_ptr<ParametersTable> PT) {
	return make_shared<IPDBrain>(ins, outs, PT);
}

#endif /* defined(__BasicMarkovBrainTemplate__IPDBrain__) */
