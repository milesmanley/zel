// Copyright (c) 2017 The PIVX developers
// Copyright (c) 2020 The Zel developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or https://www.opensource.org/licenses/mit-license.php.

#include "zelnode/sporkdb.h"
#include "zelnode/spork.h"

static const char DB_ZELNODE_CACHE_DATA = 'd';

CSporkDB::CSporkDB(size_t nCacheSize, bool fMemory, bool fWipe) : CDBWrapper(GetDataDir() / "sporks", nCacheSize, fMemory, fWipe) {}

bool CSporkDB::WriteSpork(const int nSporkId, const CSporkMessage& spork)
{
    LogPrintf("Wrote spork %s to database\n", sporkManager.GetSporkNameByID(nSporkId));
    return Write(nSporkId, spork);

}

bool CSporkDB::ReadSpork(const int nSporkId, CSporkMessage& spork)
{
    return Read(nSporkId, spork);
}

bool CSporkDB::SporkExists(const int nSporkId)
{
    return Exists(nSporkId);
}

