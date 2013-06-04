#include <stdio.h>
#include <string>

#include "compare.h"

#include "rice/Array.hpp"
#include "rice/Module.hpp"

bool VerifyUserWrapper(Rice::Array _db, Rice::Array _print) {
	unsigned char *db, *print;
	db = (unsigned char*) malloc(_db.size());
	print = (unsigned char *) malloc(_print.size());

	if(!db || !print) return false;

	for(unsigned int i = 0; i < _db.size(); i++) {
		db[i] = from_ruby<unsigned char>(_db[i]);
	}
	for(unsigned int i = 0; i < _print.size(); i++) {
		print[i] = from_ruby<unsigned char>(_print[i]);
	}

	bool result = VerifyUser(db, _db.size(), print, _print.size());

	free(db);
	free(print);

	return result;
}

Rice::Object LoadPrintWrapper(std::string file) {
	unsigned char *print;
	unsigned int printSize;

	LoadPrint(file, &print, &printSize);

	Rice::Array result;
	for(unsigned int i = 0; i < printSize; i++) {
		result.push(print[i]);
	}
	return result;
}

extern "C"
void Init_fingerprint() {
	Rice::Module rb_mKeyMe = Rice::define_module("KeyMe");

	Rice::Module rb_mFingerprint = rb_mKeyMe.define_module("Fingerprint")
		.define_singleton_method("verify_user", &VerifyUserWrapper)
		.define_singleton_method("load_print", &LoadPrintWrapper);
}
