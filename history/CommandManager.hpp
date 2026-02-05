/*
//File: CommandManager.hpp
// Author: Abril Sifuentes
// Date: 11/19/2025
// functions CommandManager.hpp 
*/
#pragma once
#include <string>
#include "history/Command.hpp" 
#include<vector>
#include<stack>
#include<memory>




class CommandManager{
	private:
		std::stack<std::shared_ptr<Command>> undo_stack;
		std::stack<std::shared_ptr<Command>> redo_stack;
		

	public: 
		CommandManager() = default;
		void doCommand(const std::shared_ptr<Command>& command);
		void undo();
		void redo();
		bool canUndo() const;
		bool canRedo() const;
};
