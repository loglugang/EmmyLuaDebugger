/*
* Copyright (c) 2019. tangzx(love.tangzx@qq.com)
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "types.h"
#include "emmy_core.h"

Variable::Variable(): nameType(LUA_TSTRING){
}

Variable::~Variable() {
	for (auto child : children) {
		delete child;
	}
}

Stack::Stack(): level(0), line(0) {
}

Stack::~Stack() {
	for (auto var : localVariables) {
		delete var;
	}
	for (auto var : upvalueVariables) {
		delete var;
	}
}

Variable* Stack::CreateVariable() {
	auto variable = new Variable();
	return variable;
}
