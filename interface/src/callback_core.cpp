/* 
 * Copyright (c) 2014 Regents of the University of California. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. The names of its contributors may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * *********************************************************************************************** *
 * CARLsim
 * created by: 		(MDR) Micah Richert, (JN) Jayram M. Nageswaran
 * maintained by:	(MA) Mike Avery <averym@uci.edu>, (MB) Michael Beyeler <mbeyeler@uci.edu>,
 *					(KDC) Kristofor Carlson <kdcarlso@uci.edu>
 *					(TSC) Ting-Shuo Chou <tingshuc@uci.edu>
 *
 * CARLsim available from http://socsci.uci.edu/~jkrichma/CARLsim/
 * Ver 2/21/2014
 */
#include <stdio.h>
#include <callback_core.h>
#include <callback.h>

/// **************************************************************************************************************** ///
/// Classes for relay callback
/// **************************************************************************************************************** ///

SpikeGeneratorCore::SpikeGeneratorCore(CARLsim* c, SpikeGenerator* s) {
	carlsim = c;
	sGen = s;
}

unsigned int SpikeGeneratorCore::nextSpikeTime(CpuSNN* s, int grpId, int i,
											unsigned int currentTime, unsigned int lastScheduledSpikeTime) {
	if (sGen != NULL)
		return sGen->nextSpikeTime(carlsim, grpId, i, currentTime, lastScheduledSpikeTime);
	else
		return 0xFFFFFFFF;
}

ConnectionGeneratorCore::ConnectionGeneratorCore(CARLsim* c, ConnectionGenerator* cg) {
	carlsim = c;
	cGen = cg;
}

void ConnectionGeneratorCore::connect(CpuSNN* s, int srcGrpId, int i, int destGrpId, int j, float& weight, float& maxWt,
							float& delay, bool& connected) {
	if (cGen != NULL)
		cGen->connect(carlsim, srcGrpId, i, destGrpId, j, weight, maxWt, delay, connected);
}

SpikeMonitorCore::SpikeMonitorCore(CARLsim* c, SpikeMonitor* s) {
	carlsim = c;
	sMon = s;
}

void SpikeMonitorCore::update(CpuSNN* s, int grpId, unsigned int* Nids, unsigned int* timeCnts) {
	if (sMon != NULL)
		sMon->update(carlsim, grpId, Nids, timeCnts);
}

GroupMonitorCore::GroupMonitorCore(CARLsim* c, GroupMonitor* g) {
	carlsim = c;
	gMon = g;
}

void GroupMonitorCore::update(CpuSNN* s, int grpID, float* grpDA, int numData) {
	if (gMon != NULL)
		gMon->update(carlsim, grpID, grpDA, numData);
}

NetworkMonitorCore::NetworkMonitorCore(CARLsim* c, NetworkMonitor* n) {
	carlsim = c;
	nMon = n;
}

void NetworkMonitorCore::update(CpuSNN* s, int grpIdPre, int grpIdPost, float* weight, int numData) {
	if (nMon != NULL)
		nMon->update(carlsim, grpIdPre, grpIdPost, weight, numData);
}