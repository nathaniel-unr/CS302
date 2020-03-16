#include "Stack.h"
#include <cmath>
#include <iostream>

const char *ERR_MISSING_OPEN_PARENTHESES =
    "Missing corresponding '(' in expression";
const char *ERR_MISSING_CLOSE_PARENTHESES =
    "Missing corresponding ')' in expression";
const char *ERR_INVALID_CHAR = "Invalid character detected in input";
const char *ERR_INVALID_EXPR = "Invalid Expression";

std::string read_line() {
  std::string ret = "";
  getline(std::cin, ret);
  return ret;
}

int get_op_precedence(char c) {
  switch (c) {
  case '+':
    return 10;
  case '-':
    return 10;
  case '/':
    return 20;
  case '*':
    return 20;
  case '^':
    return 30;
  case '(':
    return 40;
  case ')':
    return 40;
  default:
    return -10;
  }
}

bool has_greater_precedence(char op1, char op2) {
  size_t op1_p = get_op_precedence(op1);
  size_t op2_p = get_op_precedence(op2);
  return op1_p > op2_p;
}

bool isoperator(char c) {
  return c == '+' || c == '-' || c == '/' || c == '*' || c == '^';
}

std::string infix_to_postfix(const std::string &infix, const char **error) {
  std::string postfix = "";
  Stack<char> operator_stack;
  for (size_t i = 0; i < infix.size(); i++) {
    char c = infix[i];
    char top;
    switch (c) {
    case '(':
      operator_stack.push(c);
      break;
    case ')':
      if (operator_stack.isEmpty()) {
        *error = ERR_MISSING_OPEN_PARENTHESES;
        return postfix;
      }
      top = operator_stack.peek();
      while (top != '(') {
        postfix += top;
        operator_stack.pop();
        if (operator_stack.isEmpty()) {
          *error = ERR_MISSING_OPEN_PARENTHESES;
          return postfix;
        }
        top = operator_stack.peek();
      }
      operator_stack.pop();
      break;
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
      while (!operator_stack.isEmpty() &&
             has_greater_precedence(operator_stack.peek(), c) &&
             operator_stack.peek() != '(') {
        postfix += operator_stack.peek();
        operator_stack.pop();
      }
      operator_stack.push(c);
      break;
    default:
      if (isdigit(c)) {
        postfix += c;
      } else if (isspace(c)) {
        // NOP
      } else {
        *error = ERR_INVALID_CHAR;
        return postfix;
      }
    }
  }
  while (!operator_stack.isEmpty()) {
    char c = operator_stack.peek();
    if (c == '(') {
      *error = ERR_MISSING_CLOSE_PARENTHESES;
      return postfix;
    }
    postfix += c;
    operator_stack.pop();
  }
  return postfix;
}

float eval_postfix(const std::string &postfix, const char **error) {
  Stack<float> opstack;
  for (size_t i = 0; i < postfix.size(); i++) {
    char c = postfix[i];
    if (isoperator(c)) {
      if (opstack.isEmpty()) {
        *error = ERR_INVALID_EXPR;
        return 0.0;
      }
      float op1 = opstack.peek();
      opstack.pop();

      if (opstack.isEmpty()) {
        *error = ERR_INVALID_EXPR;
        return 0.0;
      }
      float op2 = opstack.peek();
      opstack.pop();

      float res = 0.0;
      switch (c) {
      case '+':
        res = op1 + op2;
        break;
      case '-':
        res = op1 - op2;
        break;
      case '*':
        res = op1 * op2;
        break;
      case '/':
        res = op2 / op1;
        break;
      case '^':
        res = pow(op2, op1);
        break;
      default:
        *error = ERR_INVALID_CHAR;
        return 0.0;
      }

      opstack.push(res);
    } else if (isdigit(c)) {
      opstack.push((float)(c - '0'));
    } else {
      *error = ERR_INVALID_CHAR;
      return 0.0;
    }
  }

  if (opstack.isEmpty()) {
    *error = ERR_INVALID_EXPR;
    return 0.0;
  }
  float ret = opstack.peek();
  opstack.pop();
  if (!opstack.isEmpty()) {
    *error = ERR_INVALID_EXPR;
    return 0.0;
  }
  return ret;
}

int main() {
  std::cout << "Enter infix expression: " << std::endl;
  std::string infix = read_line();
  const char *error_str = NULL;
  std::string postfix = infix_to_postfix(infix, &error_str);
  if (error_str != NULL) {
    std::cout << "Error: " << error_str << std::endl;
    return 1;
  }
  std::cout << "Postfix Expression:  " << postfix << std::endl;
  float result = eval_postfix(postfix, &error_str);
  if (error_str != NULL) {
    std::cout << "Error: " << error_str << std::endl;
    return 1;
  }
  std::cout << "Expression Result: " << result << std::endl;
  return 0;
}