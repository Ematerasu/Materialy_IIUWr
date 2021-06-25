using System;

namespace Zadanie3
{
    public abstract class TreeVisitor
    {
        public abstract void Visit(TreeNode t);
        public abstract void Visit(TreeLeaf l);
    }

    public class DepthTreeVisitor : TreeVisitor
    {
        private int currDepth = -1;
        public int maxDepth = 0;

        public override void Visit(TreeNode t)
        {
            currDepth += 1;
            t.Left.Accept(this);
            t.Right.Accept(this);
            currDepth -= 1;
        }
        public override void Visit(TreeLeaf l)
        {
            currDepth += 1;
            maxDepth = currDepth > maxDepth ? currDepth : maxDepth;
            currDepth -= 1;
        }
        
    }
    public abstract class Tree
    {
        public virtual void Accept(TreeVisitor visitor)
        {

        }
    }

    public class TreeNode : Tree
    {
        public Tree Left { get; set; }
        public Tree Right { get; set; }

        public override void Accept(TreeVisitor visitor)
        {
            visitor.Visit(this);
        }
    }

    public class TreeLeaf : Tree
    {
        public int val { get; set; }
        public override void Accept(TreeVisitor visitor)
        {
            visitor.Visit(this);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            TreeNode root = new TreeNode()
            {
                Left = new TreeNode()
                {
                    Left = new TreeNode()
                    {
                        Left = new TreeLeaf() { val = 2 },
                        Right = new TreeLeaf() { val = 0 }
                    },
                    Right = new TreeLeaf() { val = 5 }
                },
                Right = new TreeLeaf() { val = 4 }
            };
            DepthTreeVisitor visitor = new DepthTreeVisitor();
            visitor.Visit(root);
            Console.WriteLine(visitor.maxDepth);
        }
    }
}
