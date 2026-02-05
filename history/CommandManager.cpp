/*
//File: CommandManager.cpp
// Author: Abril Sifuentes
// Date: 11/19/2025
// functions  implementation CommandManager.hpp 
*/
#include"history/CommandManager.hpp"

/**
 * @brief Executes a new command.
 *
 * @param command A const reference to a shared_ptr<Command> to be executed.
 * @post
 * 1. The command's execute() method is called.
 * 2. The command is pushed onto the undo stack.
 * 3. The redo stack is cleared.
 */
    void CommandManager::doCommand(const std::shared_ptr<Command>& command){
        command->execute();
        undo_stack.push(command);
        while(!redo_stack.empty()){
            redo_stack.pop();
        }
    }

/**
 * @brief Undoes the most recent command.
 * @post
 * 1. If the undo stack is not empty:
 * 2. The top command is popped from the undo stack.
 * 3. The command's undo() method is called.
 * 4. The command is pushed onto the redo stack.
 */
    void CommandManager::undo(){
         if(!undo_stack.empty()){
            auto cd = undo_stack.top();
            undo_stack.pop();
            cd->undo();
            redo_stack.push(cd);
        }
    }
/**
 * @brief Redoes the most recently undone command.
 * @post
 * 1. If the redo stack is not empty:
 * 2. The top command is popped from the redo stack.
 * 3. The command's redo() method is called.
 * 4. The command is pushed onto the undo stack.
 */
    void CommandManager::redo(){
        if(!redo_stack.empty()){
            auto cd = redo_stack.top();
            redo_stack.pop();
            cd->redo();
            undo_stack.push(cd);

        }
    }

/**
 * @brief Checks if an undo operation is possible.
 * @return True if there are moves to be undone, false otherwise.
 */
    bool CommandManager::canUndo() const{
        return !undo_stack.empty();
    }

/**
 * @brief Checks if a redo operation is possible.
 * @return True if there are moves to be redone, false otherwise.
 */
    bool CommandManager::canRedo() const{
        return !redo_stack.empty();
    }
