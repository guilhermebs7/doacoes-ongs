'use client';

import React, { useState } from 'react';
import Image from 'next/image';
import { Grid, MapPin, Plus, Search, User } from 'lucide-react';

const Header2: React.FC = () => {
  const [showLocation, setShowLocation] = useState(false);
  const [location, setLocation] = useState('PE');

  const toggleLocation = () => setShowLocation(!showLocation);

  const estados = ['PE', 'SP', 'RJ'];

  function handleClick(opcao: string) {
    console.log(`Clique em: ${opcao}`);
  }

  return (
    <header className="w-full flex items-center justify-center px-6 py-4 border-b border-gray-300 bg-white text-xl gap-20">
      
      {/* Logo */}
      <div className="flex items-center">
        <Image
          src="/assets/logo.png"
          alt="Logo Doe Fácil"
          width={90}
          height={90}
          className="h-20 w-auto"
          priority
        />
      </div>

      {/* Search */}
      <div className="flex items-center border border-gray-300 rounded-xl w-[800px] h-14 bg-gray-50 shadow-sm relative">
        <input
          type="text"
          placeholder='Buscar “Roupas”...'
          className="px-6 py-4 text-xl w-full bg-transparent focus:outline-none placeholder:text-gray-500"
        />

        {/* Localização com dropdown */}
        <div className="relative h-full flex items-center border-l border-gray-300">
          <div
            onClick={toggleLocation}
            className="px-5 flex items-center gap-2 text-gray-700 cursor-pointer"
          >
            <span className="text-lg font-semibold">{location}</span>
            <MapPin size={26} />
          </div>

          {showLocation && (
            <div className="absolute top-full right-0 mt-2 bg-white border border-gray-300 rounded-md shadow-md z-50">
              {estados.map((uf) => (
                <button
                  key={uf}
                  onClick={() => {
                    setLocation(uf);
                    setShowLocation(false);
                  }}
                  className="px-4 py-2 w-full text-left hover:bg-gray-100"
                >
                  {uf}
                </button>
              ))}
            </div>
          )}
        </div>

        {/* Botão buscar */}
        <button
          type="button"
          onClick={() => console.log('Buscar clicado')}
          className="px-5 text-gray-600 hover:text-black cursor-pointer"
        >
          <Search size={26} />
        </button>
      </div>

      {/* Menu */}
      <nav className="flex items-center gap-8 text-lg text-gray-800 font-semibold">
        <div
          onClick={() => handleClick('Meus Anúncios')}
          className="flex items-center gap-2 cursor-pointer hover:text-black"
        >
          <Grid size={24} />
          <span>Meus Anúncios</span>
        </div>

        <div
          onClick={() => handleClick('Adicionar Anúncio')}
          className="flex items-center gap-2 cursor-pointer text-black hover:text-black transition"
        >
          <Plus size={24} />
          <span>Adicionar Anúncio</span>
        </div>
      </nav>

      {/* Ícone de Usuário */}
      <div
        onClick={() => handleClick('Perfil do Usuário')}
        className="cursor-pointer hover:text-black"
      >
        <User size={42} />
      </div>
    </header>
  );
};

export default Header2;
