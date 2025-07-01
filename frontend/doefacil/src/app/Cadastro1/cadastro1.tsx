'use client';

import { useState } from 'react';
import { useRouter } from 'next/navigation';
import { RadioGroup } from '@headlessui/react';
import { User, Building2 } from 'lucide-react';

const Cadastro = () => {
  const [tipoUsuario, setTipoUsuario] = useState<'doador' | 'ong' | null>(null);
  const router = useRouter();

  const handleSelecionar = (tipo: 'doador' | 'ong') => {
    setTipoUsuario(tipo);
    router.push(`/${tipo}`); // redireciona para /doador ou /ong
  };

  return (
    <div className="flex flex-col items-center justify-center min-h-screen px-4 bg-gray-50">
      <h1 className="text-3xl font-bold text-center mb-2">Junte-se à Nossa Comunidade</h1>
      <p className="text-gray-600 text-center mb-8">
        Cadastre-se e faça parte desta rede de solidariedade.
      </p>

      <div className="bg-white shadow-md rounded-xl w-full max-w-md p-6">
        <h2 className="text-xl font-semibold text-blue-600 text-center mb-2">Cadastro de Usuário</h2>
        <p className="text-sm text-gray-500 text-center mb-6">
          Cadastre-se como Doador ou ONG para participar da plataforma
        </p>

        <RadioGroup value={tipoUsuario} onChange={handleSelecionar}>
          <RadioGroup.Option value="doador">
            {({ checked }) => (
              <div
                className={`border rounded-lg p-4 flex items-center space-x-4 cursor-pointer mb-3 ${
                  checked ? 'border-blue-600 bg-blue-50' : 'border-gray-300'
                }`}
              >
                <User className="text-blue-600" />
                <div>
                  <p className="font-semibold">Doador</p>
                  <p className="text-sm text-gray-500">Pessoa física que deseja doar itens</p>
                </div>
              </div>
            )}
          </RadioGroup.Option>

          <RadioGroup.Option value="ong">
            {({ checked }) => (
              <div
                className={`border rounded-lg p-4 flex items-center space-x-4 cursor-pointer ${
                  checked ? 'border-green-600 bg-green-50' : 'border-gray-300'
                }`}
              >
                <Building2 className="text-green-600" />
                <div>
                  <p className="font-semibold">ONG</p>
                  <p className="text-sm text-gray-500">Organização que recebe doações</p>
                </div>
              </div>
            )}
          </RadioGroup.Option>
        </RadioGroup>

        <div className="flex justify-between mt-6">
          <button
            onClick={() => setTipoUsuario(null)}
            className="px-4 py-2 border rounded-md text-gray-600 border-gray-300 hover:bg-gray-100"
          >
            Limpar
          </button>
          <button
            onClick={() => tipoUsuario && router.push(`/${tipoUsuario}`)}
            className="px-6 py-2 bg-black text-white rounded-md hover:bg-gray-800"
          >
            Cadastrar
          </button>
        </div>
      </div>
    </div>
  );
};

export default Cadastro;
