'use client';

import React, { useState } from 'react';
import Image from 'next/image';
import Header2 from '@/components/Header2';
import { ChevronLeft, ChevronRight } from 'lucide-react';

const categorias = [
  'Celulares', 'Brinquedos', 'Decoração', 'Eletro', 'Móveis',
  'Esportes', 'Hobbies', 'Agro', 'Roupas', 'Infantil', 'Mais'
];

const categoriasComImagem = ['Móveis', 'Roupas', 'Calçados'];

const imagensCampanha = [
  '/assets/campanha.png'
];

export default function HomePage() {
  const [indexImagem, setIndexImagem] = useState(0);

  function voltarImagem() {
    setIndexImagem((old) => (old === 0 ? imagensCampanha.length - 1 : old - 1));
  }

  function avancarImagem() {
    setIndexImagem((old) => (old === imagensCampanha.length - 1 ? 0 : old + 1));
  }

  function handleCategoriaClick(categoria: string) {
    console.log(`Categoria clicada: ${categoria}`);
    // futuramente: navegar para página ou filtrar os produtos
  }

  return (
    <div className="bg-white min-h-screen">
      <Header2 />

      {/* Barra de categorias - centralizada com espaçamento */}
      <div className="flex justify-center bg-white border-b border-gray-200 px-4 py-4 overflow-x-auto scrollbar-none">
        <div className="flex gap-16 w-fit">
          {categorias.map((cat, idx) => (
            <button
              key={idx}
              onClick={() => handleCategoriaClick(cat)}
              className="whitespace-nowrap px-4 py-2 bg-gray-100 rounded-full text-lg font-medium hover:bg-gray-200 cursor-pointer transition"
            >
              {cat}
            </button>
          ))}
        </div>
      </div>

      {/* Campanha do Agasalho - carrossel com setas */}
      <div className="relative flex justify-center my-8 px-12 max-w-[900px] mx-auto">
        <Image
          src={imagensCampanha[indexImagem]}
          alt={`Campanha do Agasalho ${indexImagem + 1}`}
          width={750}
          height={300}
          className="rounded-xl object-contain"
          priority
        />

        <button
          onClick={voltarImagem}
          className="absolute left-4 top-1/2 -translate-y-1/2 bg-white bg-opacity-70 text-black rounded-full p-2 shadow hover:bg-opacity-90 cursor-pointer"
          aria-label="Imagem anterior"
        >
          <ChevronLeft size={28} />
        </button>

        <button
          onClick={avancarImagem}
          className="absolute right-4 top-1/2 -translate-y-1/2 bg-white bg-opacity-70 text-black rounded-full p-2 shadow hover:bg-opacity-90 cursor-pointer"
          aria-label="Próxima imagem"
        >
          <ChevronRight size={28} />
        </button>
      </div>

      {/* Listagem de produtos por categoria */}
      <div className="space-y-12 px-12 pb-12">
        {categoriasComImagem.map((categoria, i) => (
          <div key={i}>
            <div className="flex justify-between items-center mb-3">
              <h3 className="text-xl font-semibold">{categoria}</h3>
              <div className="flex gap-2">
                <button className="bg-gray-200 p-1 rounded-full">
                  <ChevronLeft />
                </button>
                <button className="bg-gray-200 p-1 rounded-full">
                  <ChevronRight />
                </button>
              </div>
            </div>
            <div className="grid grid-cols-2 sm:grid-cols-3 md:grid-cols-5 lg:grid-cols-6 gap-4">
              {Array.from({ length: 10 }).map((_, idx) => (
                <div
                  key={idx}
                  className="w-full aspect-square bg-gray-100 border border-gray-300 rounded"
                />
              ))}
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}
