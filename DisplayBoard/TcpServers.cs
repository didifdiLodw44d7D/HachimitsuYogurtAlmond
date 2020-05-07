using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace DisplayBoard
{
    class TcpServer
    {
        IPAddress address;
        int port;
        TcpListener listener;
        private byte[] buffer;

        public TcpServer(int port, String ipaddress)
        {
            this.port = port;
            this.address = IPAddress.Parse(ipaddress);
            this.listener = new TcpListener(this.address, this.port);
        }

        /// <summary>
        /// マルチスレッドの無限ループ
        /// </summary>
        public void Listen()
        {
            this.listener.Start();

            while (true)
            {
                TcpClient client = listener.AcceptTcpClient(); // blocking (同期でないとダメ。順番が担保されていないと、違うIPAddress で、違うデータがオブジェクトに入る可能性がある。)

                //key(add:port), value(int) ==> map に登録
                //エンドポイントから、オブジェクトを調べる。
                //渡す。

                DoWork(client);
            }
        }

        /// <summary>
        /// マルチスレッドの実行メソッド
        /// </summary>
        /// <param name="client"></param>
        private void DoWork(object client)
        {
            int ret = 0;

            var tcpClient = client as TcpClient;

            var endpoint = (IPEndPoint)tcpClient.Client.RemoteEndPoint;

            string ipaddress = endpoint.Address.ToString();

            while (true)
            {
                ret = ParseTelegram((TcpClient)client, endpoint);
                if (-1 == ret)
                {
                    Console.WriteLine("切断されました");
                    break;
                }
            }

            string line = Console.ReadLine();

        }

        private int ParseTelegram(TcpClient client, IPEndPoint endpoint)
        {
            //ストリームからバッファに読込
            NetworkStream stream = client.GetStream();
            int n;

            buffer = new byte[128];
            try
            {
                n = stream.Read(buffer, 0, buffer.Length);
            }
            catch (Exception ex)
            {
                return -1;
            }

            Console.WriteLine(n);

            var tmp = buffer;
            buffer = new byte[n];
            Buffer.BlockCopy(tmp, 0, buffer, 0, n);

            //処理の受付
            string filename = Encoding.ASCII.GetString(buffer);

            Console.WriteLine(filename);

            return 0;
        }
    }
}
