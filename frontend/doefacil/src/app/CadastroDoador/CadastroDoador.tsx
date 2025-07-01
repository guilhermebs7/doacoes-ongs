'use client';

import { useState } from 'react';
import { User, Building2 } from 'lucide-react';

export default function CadastroDoador() {
  const [tipoUsuario, setTipoUsuario] = useState<'doador' | 'ong'>('doador');
  const [form, setForm] = useState({
    nome: '',
    cpf: '',
    email: '',
    senha: '',
    confirmarSenha: '',
  });

  const handleChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    setForm({ ...form, [e.target.name]: e.target.value });
  };

  const limpar = () => {
    setForm({
      nome: '',
      cpf: '',
      email: '',
      senha: '',
      confirmarSenha: '',
    });
  };

  return (
    <div className="flex flex-col items-center justify-center min-h-screen px-4 bg-gray-50">
      <h1 className="text-3xl font-bold text-center mb-2">Junte-se à Nossa Comunidade</h1>
      <p className="text-gray-600 text-center mb-8">
        Cadastre-se e faça parte desta rede de solidariedade.
      </p>

      <div className="bg-white shadow-md rounded-xl w-full max-w-md p-6 border border-blue-100">
        <h2 className="text-xl font-semibold text-blue-600 text-center mb-2">Cadastro de Usuário</h2>
        <p className="text-sm text-gray-500 text-center mb-6">
          Cadastre-se como Doador ou ONG para participar da plataforma
        </p>

        {/* Tipo de Usuário */}
        <div className="space-y-3 mb-6">
          <div
            onClick={() => setTipoUsuario('doador')}
            className={`border rounded-lg p-3 flex items-center cursor-pointer space-x-3 ${
              tipoUsuario === 'doador' ? 'border-blue-500 bg-blue-50' : 'border-gray-300'
            }`}
          >
            <User className="text-blue-600" />
            <div>
              <p className="font-medium">Doador</p>
              <p className="text-sm text-gray-500">Pessoa física que deseja doar itens</p>
            </div>
          </div>

          <div
            onClick={() => setTipoUsuario('ong')}
            className={`border rounded-lg p-3 flex items-center cursor-pointer space-x-3 ${
              tipoUsuario === 'ong' ? 'border-green-500 bg-green-50' : 'border-gray-300'
            }`}
          >
            <Building2 className="text-green-600" />
            <div>
              <p className="font-medium">ONG</p>
              <p className="text-sm text-gray-500">Organização que recebe doações</p>
            </div>
          </div>
        </div>

        {/* Formulário de Doador */}
        {tipoUsuario === 'doador' && (
          <form className="space-y-4">
            <div>
              <label className="text-sm font-medium">Nome completo *</label>
              <input
                type="text"
                name="nome"
                value={form.nome}
                onChange={handleChange}
                placeholder="Digite seu nome completo"
                className="w-full mt-1 p-2 border rounded-md"
              />
            </div>

            <div>
              <label className="text-sm font-medium">CPF *</label>
              <input
                type="text"
                name="cpf"
                value={form.cpf}
                onChange={handleChange}
                placeholder="000.000.000-00"
                className="w-full mt-1 p-2 border rounded-md"
              />
            </div>

            <div>
              <label className="text-sm font-medium">E-mail *</label>
              <input
                type="email"
                name="email"
                value={form.email}
                onChange={handleChange}
                placeholder="seu@email.com"
                className="w-full mt-1 p-2 border rounded-md"
              />
            </div>

            <div>
              <label className="text-sm font-medium">Senha *</label>
              <input
                type="password"
                name="senha"
                value={form.senha}
                onChange={handleChange}
                placeholder="Digite sua senha"
                className="w-full mt-1 p-2 border rounded-md"
              />
            </div>

            <div>
              <label className="text-sm font-medium">Confirmar Senha *</label>
              <input
                type="password"
                name="confirmarSenha"
                value={form.confirmarSenha}
                onChange={handleChange}
                placeholder="Confirme sua senha"
                className="w-full mt-1 p-2 border rounded-md"
              />
            </div>

            <div className="flex justify-between pt-4">
              <button
                type="button"
                onClick={limpar}
                className="px-4 py-2 border rounded-md text-gray-600 border-gray-300 hover:bg-gray-100"
              >
                Limpar
              </button>
              <button
                type="submit"
                className="px-6 py-2 bg-black text-white rounded-md hover:bg-gray-800"
              >
                Cadastrar
              </button>
            </div>
          </form>
        )}
      </div>
    </div>
  );
}
