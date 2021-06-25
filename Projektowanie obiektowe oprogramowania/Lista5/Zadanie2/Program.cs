using System;
using System.IO;

namespace Zadanie2
{
    //Opieram się na dokumentacji klasy Stream, dokladniej, jakie są sygnatury metod Read i Write w klasie Stream
    class CaesarStream : Stream
    {
        int offset = 0;
        Stream stream;

        public CaesarStream(Stream s, int offset)
        {
            this.offset += offset;
            this.stream = s;
        }

        public override int Read(byte[] buffer, int offset, int count)
        {
            int ret = this.stream.Read(buffer, offset, count);

            for (int i = 0; i < buffer.Length; i++) buffer[i] = (byte)(buffer[i] - (byte)this.offset);

            return ret;
        }

        public override void Write(byte[] buffer, int offset, int count)
        {
            for (int i = 0; i < buffer.Length; i++) buffer[i] = (byte)(buffer[i] + (byte)this.offset);
            this.stream.Write(buffer, offset, count);
        }

        public override bool CanRead => throw new NotImplementedException();
        public override bool CanSeek => throw new NotImplementedException();
        public override bool CanTimeout => base.CanTimeout;
        public override bool CanWrite => throw new NotImplementedException();
        public override long Position { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }
        public override long Seek(long offset, SeekOrigin origin)
        {
            throw new NotImplementedException();
        }
        public override void SetLength(long value)
        {
            throw new NotImplementedException();
        }
        public override long Length => throw new NotImplementedException();
        public override void Flush()
        {
            throw new NotImplementedException();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}
