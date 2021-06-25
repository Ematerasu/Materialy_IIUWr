using System;
using System.Collections.Generic;
using System.Reflection.Metadata.Ecma335;

namespace Zadanie2
{
    public class Context
    {
        private Dictionary<string, bool> _localVariables = new Dictionary<string, bool>();
        public bool GetValue(string VariableName) 
        {
            if (_localVariables.ContainsKey(VariableName))
            {
                return _localVariables[VariableName];
            }
            else
            {
                throw new ArgumentException();
            }
        }
        public void SetValue(string VariableName, bool Value)
        {
            if (_localVariables.ContainsKey(VariableName))
            {
                _localVariables.Remove(VariableName);
            }
            _localVariables.Add(VariableName, Value);
        }
    }

    public abstract class AbstractExpression
    {
        public abstract bool Interpret(Context context);
    }

    public class ConstExpression : AbstractExpression
    {
        public string name;
        public override bool Interpret(Context context)
        {
            switch (name)
            {
                case "false":
                    return false;
                case "true":
                    return true;
                default:
                    throw new ArgumentException();
            }
        }
    }

    public class VariableExpression : AbstractExpression 
    {
        public string name;

        public override bool Interpret(Context context)
        {
           return context.GetValue(name);
        }
    }
    public class BinaryExpression : AbstractExpression 
    {
        public AbstractExpression Left;
        public AbstractExpression Right;
        public string Operator;

        public override bool Interpret(Context context)
        {
            switch (Operator)
            {
                case "||":
                    return this.Left.Interpret(context) || this.Right.Interpret(context);
                case "&&":
                    return this.Left.Interpret(context) && this.Right.Interpret(context);
                default:
                    throw new ArgumentException();
            }
        }
    }
    public class UnaryExpression : AbstractExpression 
    {
        public AbstractExpression Expression;
        public string Operator;
        public override bool Interpret(Context context)
        {
            switch (Operator)
            {
                case "!":
                    return !this.Expression.Interpret(context);
                default:
                    throw new ArgumentException();
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Context ctx = new Context();
            ctx.SetValue("x", false);
            ctx.SetValue("y", true);
            AbstractExpression exp = new BinaryExpression()
            {

                Left = new VariableExpression() { name = "x" },
                Right = new VariableExpression() { name = "y"},
                Operator = "||"
            };
            Console.WriteLine(exp.Interpret(ctx));
        }
    }
}
