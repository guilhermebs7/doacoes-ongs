'use client';

import React, { useState } from 'react';
import { useRouter } from 'next/navigation';
import { FaEnvelope, FaLock, FaEye, FaEyeSlash, FaUserPlus, FaSignInAlt } from 'react-icons/fa';

const Login: React.FC = () => {
  const router = useRouter();
  const [email, setEmail] = useState('');
  const [senha, setSenha] = useState('');
  const [mostrarSenha, setMostrarSenha] = useState(false);

  const handleLogin = (e: React.FormEvent) => {
    e.preventDefault();
    // lógica de login aqui
    console.log({ email, senha });
  };

  // Função para ir para a página de cadastro
  const handleCadastro = () => {
    router.push('/cadastro'); // aqui você cria a página /cadastro depois
  };

  return (
    <div className="min-h-screen flex items-center justify-center bg-white">
      <div className="w-full max-w-md p-6">
        <div className="flex flex-col items-center mb-6">
          <div className="text-4xl mb-2">❤️</div>
          <h1 className="text-xl font-bold text-center text-blue-900">DOE<br />FÁCIL</h1>
        </div>

        <p className="text-center text-gray-600 mb-6">Entre com suas credenciais para acessar sua conta</p>

        <form onSubmit={handleLogin} className="space-y-4">
          {/* Campo de Email */}
          <div>
            <label className="block text-sm font-medium text-gray-700">Email</label>
            <div className="relative mt-1">
              <span className="absolute inset-y-0 left-0 flex items-center pl-3 text-gray-500">
                <FaEnvelope />
              </span>
              <input
                type="email"
                value={email}
                onChange={(e) => setEmail(e.target.value)}
                placeholder="seu@email.com"
                required
                className="w-full pl-10 pr-3 py-2 border rounded-md focus:outline-none focus:ring-2 focus:ring-blue-500"
              />
            </div>
          </div>

          {/* Campo de Senha */}
          <div>
            <label className="block text-sm font-medium text-gray-700">Senha</label>
            <div className="relative mt-1">
              <span className="absolute inset-y-0 left-0 flex items-center pl-3 text-gray-500">
                <FaLock />
              </span>
              <input
                type={mostrarSenha ? 'text' : 'password'}
                value={senha}
                onChange={(e) => setSenha(e.target.value)}
                required
                className="w-full pl-10 pr-10 py-2 border rounded-md focus:outline-none focus:ring-2 focus:ring-blue-500"
              />
              <span
                className="absolute inset-y-0 right-0 flex items-center pr-3 text-gray-500 cursor-pointer"
                onClick={() => setMostrarSenha(!mostrarSenha)}
              >
                {mostrarSenha ? <FaEyeSlash /> : <FaEye />}
              </span>
            </div>
          </div>

          {/* Botão de Entrar */}
          <button
            type="submit"
            className="w-full flex items-center justify-center gap-2 py-2 px-4 bg-blue-600 text-white rounded-md hover:bg-blue-700 transition cursor-pointer"
          >
            <FaSignInAlt />
            Entrar
          </button>
        </form>

        {/* Separador */}
        <div className="flex items-center my-4">
          <hr className="flex-grow border-t" />
          <span className="mx-4 text-gray-400">ou</span>
          <hr className="flex-grow border-t" />
        </div>

        {/* Botão de cadastro */}
        <button
          onClick={handleCadastro}
          className="w-full flex items-center justify-center gap-2 py-2 px-4 border border-gray-300 rounded-md hover:bg-gray-50 transition cursor-pointer"
        >
          <FaUserPlus />
          Não tenho conta - Cadastrar-se
        </button>
      </div>
    </div>
  );
};

export default Login;
