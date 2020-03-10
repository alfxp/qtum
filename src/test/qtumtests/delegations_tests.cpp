#include <boost/test/unit_test.hpp>
#include <qtumtests/test_utils.h>
#include <script/standard.h>
#include <chainparams.h>
#include <qtum/qtumdelegation.h>

namespace DelegationTest{

const dev::u256 GASLIMIT = dev::u256(2500000);
const dev::h256 HASHTX = dev::h256(ParseHex("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
std::vector<unsigned char> DELEGATION_CODE = ParseHex("608060405234801561001057600080fd5b506117b0806100206000396000f3fe608060405234801561001057600080fd5b50600436106100415760003560e01c80633d666e8b146100465780634c0e968c14610050578063bffe348614610138575b600080fd5b61004e61023c565b005b6101366004803603606081101561006657600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190803560ff169060200190929190803590602001906401000000008111156100b057600080fd5b8201836020820111156100c257600080fd5b803590602001918460018302840111640100000000831117156100e457600080fd5b91908080601f016020809104026020016040519081016040528093929190818152602001838380828437600081840152601f19601f820116905080830192505050505050509192919290505050610428565b005b61017a6004803603602081101561014e57600080fd5b81019080803573ffffffffffffffffffffffffffffffffffffffff169060200190929190505050610dbb565b604051808573ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020018460ff1660ff16815260200183815260200180602001828103825283818151815260200191508051906020019080838360005b838110156101fe5780820151818401526020810190506101e3565b50505050905090810190601f16801561022b5780820380516001836020036101000a031916815260200191505b509550505050505060405180910390f35b60008060003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000206001015414156102d7576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252603281526020018061174a6032913960400191505060405180910390fd5b3373ffffffffffffffffffffffffffffffffffffffff166000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff167f7fe28d2d0b16cf95b5ea93f4305f89133b3892543e616381a1336fc1e7a01fa060405160405180910390a36000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff168152602001908152602001600020600080820160006101000a81549073ffffffffffffffffffffffffffffffffffffffff02191690556000820160146101000a81549060ff021916905560018201600090556002820160006104249190611564565b5050565b3373ffffffffffffffffffffffffffffffffffffffff168373ffffffffffffffffffffffffffffffffffffffff1614156104ca576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260178152602001807f43616e6e6f742064656c656761746520746f2073656c6600000000000000000081525060200191505060405180910390fd5b600073ffffffffffffffffffffffffffffffffffffffff168373ffffffffffffffffffffffffffffffffffffffff16141561056d576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260168152602001807f496e76616c6964207374616b657220616464726573730000000000000000000081525060200191505060405180910390fd5b60648260ff1611156105ca576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260348152602001806116966034913960400191505060405180910390fd5b6041815114610624576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260248152602001806116ca6024913960400191505060405180910390fd5b61062f818433610eb0565b6106a1576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260158152602001807f496e76616c696420506f44207369676e6174757265000000000000000000000081525060200191505060405180910390fd5b8273ffffffffffffffffffffffffffffffffffffffff166000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1614801561079057508160ff166000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060000160149054906101000a900460ff1660ff16145b80156108c55750806040516020018082805190602001908083835b602083106107ce57805182526020820191506020810190506020830392506107ab565b6001836020036101000a038019825116818451168082178552505050505050905001915050604051602081830303815290604052805190602001206000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060020160405160200180828054600181600116156101000203166002900480156108a85780601f106108865761010080835404028352918201916108a8565b820191906000526020600020905b815481529060010190602001808311610894575b505091505060405160208183030381529060405280519060200120145b15610938576040517f08c379a00000000000000000000000000000000000000000000000000000000081526004018080602001828103825260198152602001807f44656c65676174696f6e20616c7265616479206578697374730000000000000081525060200191505060405180910390fd5b60008060003373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000206001015414158015610a1757508273ffffffffffffffffffffffffffffffffffffffff166000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1614155b15610ad8573373ffffffffffffffffffffffffffffffffffffffff166000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff167f7fe28d2d0b16cf95b5ea93f4305f89133b3892543e616381a1336fc1e7a01fa060405160405180910390a35b3373ffffffffffffffffffffffffffffffffffffffff168373ffffffffffffffffffffffffffffffffffffffff167fa23803f3b2b56e71f2921c22b23c32ef596a439dbe03f7250e6b58a30eb910b5844385604051808460ff1660ff16815260200183815260200180602001828103825283818151815260200191508051906020019080838360005b83811015610b7c578082015181840152602081019050610b61565b50505050905090810190601f168015610ba95780820380516001836020036101000a031916815260200191505b5094505050505060405180910390a3826000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060000160006101000a81548173ffffffffffffffffffffffffffffffffffffffff021916908373ffffffffffffffffffffffffffffffffffffffff160217905550816000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060000160146101000a81548160ff021916908360ff160217905550436000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff16815260200190815260200160002060010181905550806000803373ffffffffffffffffffffffffffffffffffffffff1673ffffffffffffffffffffffffffffffffffffffff1681526020019081526020016000206002019080519060200190610d2d9291906115ac565b50621e94805a1015610d8a576040517f08c379a000000000000000000000000000000000000000000000000000000000815260040180806020018281038252605c8152602001806116ee605c913960600191505060405180910390fd5b60005a90505b600115610db5576000600181905550621e84805a820310610db057610db5565b610d90565b50505050565b60006020528060005260406000206000915090508060000160009054906101000a900473ffffffffffffffffffffffffffffffffffffffff16908060000160149054906101000a900460ff1690806001015490806002018054600181600116156101000203166002900480601f016020809104026020016040519081016040528092919081815260200182805460018160011615610100020316600290048015610ea65780601f10610e7b57610100808354040283529160200191610ea6565b820191906000526020600020905b815481529060010190602001808311610e8957829003601f168201915b5050505050905084565b600060606040518060400160405280601781526020017f155174756d205369676e6564204d6573736167653a0a2800000000000000000081525090506060610ef7856111ad565b90506000610f12610f0b88600060016113db565b6000611467565b90506000610f2d610f2689600160206113db565b600061148f565b90506000610f48610f418a602160206113db565b600061148f565b9050600060028087876040516020018083805190602001908083835b60208310610f875780518252602082019150602081019050602083039250610f64565b6001836020036101000a03801982511681845116808217855250505050505090500182805190602001908083835b60208310610fd85780518252602082019150602081019050602083039250610fb5565b6001836020036101000a038019825116818451168082178552505050505050905001925050506040516020818303038152906040526040518082805190602001908083835b60208310611040578051825260208201915060208101905060208303925061101d565b6001836020036101000a038019825116818451168082178552505050505050905001915050602060405180830381855afa158015611082573d6000803e3d6000fd5b5050506040513d602081101561109757600080fd5b8101908080519060200190929190505050604051602001808281526020019150506040516020818303038152906040526040518082805190602001908083835b602083106110fa57805182526020820191506020810190506020830392506110d7565b6001836020036101000a038019825116818451168082178552505050505050905001915050602060405180830381855afa15801561113c573d6000803e3d6000fd5b5050506040513d602081101561115157600080fd5b810190808051906020019092919050505090508773ffffffffffffffffffffffffffffffffffffffff16611187828686866114b7565b73ffffffffffffffffffffffffffffffffffffffff161496505050505050509392505050565b606060008273ffffffffffffffffffffffffffffffffffffffff1660001b905060606040518060400160405280601081526020017f30313233343536373839616263646566000000000000000000000000000000008152509050606060286040519080825280601f01601f19166020018201604052801561123d5781602001600182028038833980820191505090505b50905060008090505b60148110156113655782600485600c84016020811061126157fe5b1a60f81b7effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1916901c60f81c60ff168151811061129957fe5b602001015160f81c60f81b8260028302815181106112b357fe5b60200101907effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1916908160001a90535082600f60f81b85600c8401602081106112f757fe5b1a60f81b1660f81c60ff168151811061130c57fe5b602001015160f81c60f81b82600283026001018151811061132957fe5b60200101907effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1916908160001a9053508080600101915050611246565b50806040516020018082805190602001908083835b6020831061139d578051825260208201915060208101905060208303925061137a565b6001836020036101000a0380198251168184511680821785525050505050509050019150506040516020818303038152906040529350505050919050565b6060818301845110156113ed57600080fd5b606082156000811461140a5760405191506020820160405261145b565b6040519150601f8416801560200281840101858101878315602002848b0101015b81831015611448578051835260208301925060208101905061142b565b50868552601f19601f8301166040525050505b50809150509392505050565b6000600182018351101561147a57600080fd5b60008260018501015190508091505092915050565b600060208201835110156114a257600080fd5b60008260208501015190508091505092915050565b60006114c161162c565b8560001c816000600481106114d257fe5b6020020181815250508460ff16816001600481106114ec57fe5b6020020181815250508360001c8160026004811061150657fe5b6020020181815250508260001c8160036004811061152057fe5b60200201818152505061153161164e565b6020816080846085600019fa61154657600080fd5b8060006001811061155357fe5b602002015192505050949350505050565b50805460018160011615610100020316600290046000825580601f1061158a57506115a9565b601f0160209004906000526020600020908101906115a89190611670565b5b50565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f106115ed57805160ff191683800117855561161b565b8280016001018555821561161b579182015b8281111561161a5782518255916020019190600101906115ff565b5b5090506116289190611670565b5090565b6040518060800160405280600490602082028038833980820191505090505090565b6040518060200160405280600190602082028038833980820191505090505090565b61169291905b8082111561168e576000816000905550600101611676565b5090565b9056fe496e76616c696420666565202520286d75737420626520616e20696e7465676572206265747765656e203020616e642031303029506f4420696e76616c69642073697a652c2073686f756c642062652036352062797465734e6f7420656e6f75676820676173206c65667420746f20636f6e73756d652c20746865207265636f6d6d656e64656420676173206c696d697420746f2063616c6c20746869732066756e6374696f6e20697320322c3235302c30303044656c65676174696f6e20646f6573206e6f742065786973742c20736f2069742063616e6e6f742062652072656d6f766564a265627a7a72315820e5a7d653a17f0bec379b49df010bf7e9d0557c325a53a95c6a1fdaee983d848564736f6c63430005100032");

const int STAKER_FEE = 10;
const std::string REMOVE_BYTECODE_HEX = "3d666e8b";
const std::string STAKER_ADDRESS_HEX = "a2330f4221f31b7d5648eae85e505d73bb852b48";
const std::string ADD_BYTECODE_HEX = "4c0e968c000000000000000000000000a2330f4221f31b7d5648eae85e505d73bb852b48000000000000000000000000000000000000000000000000000000000000000a000000000000000000000000000000000000000000000000000000000000006000000000000000000000000000000000000000000000000000000000000000411f8507f6bc4eded301b61be5dde24923d6eecfe96aae2f3d3cd50e657171e0e13a6c0e114491c3e5699481c6ad45d3c358728fca5821c6aa9487254b1a3725673d00000000000000000000000000000000000000000000000000000000000000";
const std::string DELEGATE_ADDRESS_HEX = "df329c86d2d31139b2e882df0a83312a8d567d62";
const std::string POD_HEX = "1f8507f6bc4eded301b61be5dde24923d6eecfe96aae2f3d3cd50e657171e0e13a6c0e114491c3e5699481c6ad45d3c358728fca5821c6aa9487254b1a3725673d";

void genesisLoading(){
    const CChainParams& chainparams = Params();
    dev::eth::ChainParams cp(chainparams.EVMGenesisInfo(100));
    globalState->populateFrom(cp.genesisState);
    globalSealEngine = std::unique_ptr<dev::eth::SealEngineFace>(cp.createSealEngine());
    globalState->db().commit();
}

void createNewBlocks(TestChain100Setup* testChain100Setup, size_t n){
    std::function<void(size_t n)> generateBlocks = [&](size_t n){
        dev::h256 oldHashStateRoot = globalState->rootHash();
        dev::h256 oldHashUTXORoot = globalState->rootHashUTXO();
        for(size_t i = 0; i < n; i++){
            testChain100Setup->CreateAndProcessBlock({}, GetScriptForRawPubKey(testChain100Setup->coinbaseKey.GetPubKey()));
        }
        globalState->setRoot(oldHashStateRoot);
        globalState->setRootUTXO(oldHashUTXORoot);
    };

    generateBlocks(n);
}
BOOST_FIXTURE_TEST_SUITE(delegations_tests, TestChain100Setup)

BOOST_AUTO_TEST_CASE(checking_remove_bytecode_delegation){
    // Check remove delegation bytecode
    BOOST_CHECK(QtumDelegation::BytecodeRemove() == REMOVE_BYTECODE_HEX);
}

BOOST_AUTO_TEST_CASE(checking_add_bytecode_delegation){
    // Check add delegation bytecode
    std::string datahex, errorMessage;
    bool result = QtumDelegation::BytecodeAdd(STAKER_ADDRESS_HEX, STAKER_FEE, ParseHex(POD_HEX), datahex, errorMessage);
    BOOST_CHECK(result == true);
    BOOST_CHECK(errorMessage == "");
    BOOST_CHECK(datahex == ADD_BYTECODE_HEX);
}

BOOST_AUTO_TEST_CASE(checking_verify_delegation){
    // Check verify delegation
    uint160 address(ParseHex(DELEGATE_ADDRESS_HEX));
    Delegation delegation;
    delegation.staker = uint160(ParseHex(STAKER_ADDRESS_HEX));
    delegation.fee = STAKER_FEE;
    delegation.PoD = ParseHex(POD_HEX);
    BOOST_CHECK(QtumDelegation::VerifyDelegation(address, delegation) == true);
    delegation.PoD[0] = 20;
    BOOST_CHECK(QtumDelegation::VerifyDelegation(address, delegation) == false);
}

BOOST_AUTO_TEST_CASE(checking_delegations_from_events){
    // Initialize event
    DelegationEvent event;
    event.item.delegate = uint160(ParseHex(DELEGATE_ADDRESS_HEX));
    event.item.staker = uint160(ParseHex(STAKER_ADDRESS_HEX));
    event.item.fee = STAKER_FEE;
    event.item.PoD = ParseHex(POD_HEX);

    // Create list of events
    std::vector<DelegationEvent> events;
    events.push_back(event);
    event.type = DELEGATION_ADD;
    events.push_back(event);
    event.type = DELEGATION_REMOVE;
    events.push_back(event);
    event.type = DELEGATION_ADD;
    events.push_back(event);

    // Get delegations from events
    std::map<uint160, Delegation> delegations = QtumDelegation::DelegationsFromEvents(events);
    BOOST_CHECK(delegations.size() == 1);
    Delegation delegation = delegations[event.item.delegate];
    BOOST_CHECK(delegation.staker == event.item.staker);
    BOOST_CHECK(delegation.fee == event.item.fee);
    BOOST_CHECK(delegation.PoD == event.item.PoD);

    // Update delegations from events
    events.clear();
    event.type = DELEGATION_REMOVE;
    events.push_back(event);
    QtumDelegation::UpdateDelegationsFromEvents(events, delegations);
    BOOST_CHECK(delegations.size() == 0);
}

BOOST_AUTO_TEST_CASE(checking_delegations_contract){
    // Initialize
    initState();
    genesisLoading();
    createNewBlocks(this, 1000);
    dev::h256 hashTx(HASHTX);

    // Create contracts
    std::vector<QtumTransaction> txs;
    txs.push_back(createQtumTransaction(DELEGATION_CODE, 0, GASLIMIT, dev::u256(1), hashTx, dev::Address()));
    executeBC(txs);

    // Set delegation contract address
    dev::Address contractAddress = createQtumAddress(txs[0].getHashWith(), txs[0].getNVout());
    UpdateDelegationsAddress(h160Touint(contractAddress));
    QtumDelegation qtumDelegation;
    BOOST_CHECK(qtumDelegation.ExistDelegationContract() == true);

    // Call add delegation
    std::vector<QtumTransaction> txsAdd;
    QtumTransaction txAdd = createQtumTransaction(ParseHex(ADD_BYTECODE_HEX), 0, GASLIMIT, dev::u256(1), ++hashTx, contractAddress);
    txAdd.forceSender(dev::Address(DELEGATE_ADDRESS_HEX));
    txsAdd.push_back(txAdd);
    executeBC(txsAdd);

    // Get delegation for address
    Delegation delegation;
    uint160 address(ParseHex(DELEGATE_ADDRESS_HEX));
    bool contractRet = qtumDelegation.GetDelegation(address, delegation);
    BOOST_CHECK(contractRet == true);

    // Verify delegation is valid
    BOOST_CHECK(QtumDelegation::VerifyDelegation(address, delegation) == true);

    // Check staker fee
    BOOST_CHECK(delegation.fee == STAKER_FEE);

    // Call remove delegation
    std::vector<QtumTransaction> txsRemove;
    QtumTransaction txRemove = createQtumTransaction(ParseHex(REMOVE_BYTECODE_HEX), 0, GASLIMIT, dev::u256(1), ++hashTx, contractAddress);
    txRemove.forceSender(dev::Address(DELEGATE_ADDRESS_HEX));
    txsRemove.push_back(txRemove);
    executeBC(txsRemove);

    // Get delegation for address
    delegation = Delegation();
    contractRet = qtumDelegation.GetDelegation(address, delegation);
    BOOST_CHECK(contractRet == true);

    // Verify delegation is valid
    BOOST_CHECK(QtumDelegation::VerifyDelegation(address, delegation) == false);
}

BOOST_AUTO_TEST_SUITE_END()

}
