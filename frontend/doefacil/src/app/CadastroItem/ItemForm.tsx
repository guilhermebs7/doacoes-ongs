'use client'

import React, { useState } from 'react'
import { useRouter } from 'next/navigation' // importa o useRouter
import { FaPlus } from 'react-icons/fa'

type FormData = {
  nome: string
  descricao: string
  categoria: string
  cidade: string
}

const categorias = ['Eletrodomésticos', 'Roupas', 'Móveis', 'Brinquedos', 'Livros', 'Calçados', 'Higiene']

const ItemForm: React.FC = () => {
  const router = useRouter() // inicializa o router

  const [formData, setFormData] = useState<FormData>({
    nome: '',
    descricao: '',
    categoria: '',
    cidade: ''
  })

  const handleChange = (
    e: React.ChangeEvent<HTMLInputElement | HTMLTextAreaElement | HTMLSelectElement>
  ) => {
    const { name, value } = e.target
    setFormData(prev => ({ ...prev, [name]: value }))
  }

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault()
    console.log('Item cadastrado:', formData)
    alert(`Item "${formData.nome}" cadastrado com sucesso!`)

    // Limpar formulário
    handleClear()

    // Redirecionar para a página desejada, ex: /obrigado
    router.push('/obrigado') // aqui você troca pela rota que quiser
  }

  const handleClear = () => {
    setFormData({
      nome: '',
      descricao: '',
      categoria: '',
      cidade: ''
    })
  }

  return (
    <div className="max-w-4xl w-full mx-auto p-10 bg-white shadow-md rounded-2xl">
      <h2 className="text-center text-2xl font-semibold text-blue-600 mb-1">Cadastrar Item para Doação</h2>
      <p className="text-center text-gray-500 mb-6">Preencha as informações do item que deseja doar</p>

      <form onSubmit={handleSubmit} className="space-y-5">
        {/* Nome */}
        <div>
          <label className="text-sm font-medium">Nome do Item *</label>
          <input
            type="text"
            name="nome"
            placeholder="Ex: Televisão 32 polegadas Samsung"
            value={formData.nome}
            onChange={handleChange}
            className="w-full border rounded px-3 py-2 mt-1"
            required
          />
        </div>

        {/* Descrição */}
        <div>
          <label className="text-sm font-medium">Descrição *</label>
          <textarea
            name="descricao"
            placeholder="Descreva o item: estado de conservação, características especiais, etc."
            value={formData.descricao}
            onChange={handleChange}
            className="w-full border rounded px-3 py-2 mt-1"
            rows={4}
            required
          />
        </div>

        {/* Categoria */}
        <div>
          <label className="text-sm font-medium">Categoria *</label>
          <select
            name="categoria"
            value={formData.categoria}
            onChange={handleChange}
            className="w-full border rounded px-3 py-2 mt-1"
            required
          >
            <option value="">Selecione uma categoria</option>
            {categorias.map(cat => (
              <option key={cat} value={cat}>
                {cat}
              </option>
            ))}
          </select>
        </div>

        {/* Cidade */}
        <div>
          <label className="text-sm font-medium">Cidade *</label>
          <input
            type="text"
            name="cidade"
            placeholder="Ex: São Paulo - SP"
            value={formData.cidade}
            onChange={handleChange}
            className="w-full border rounded px-3 py-2 mt-1"
            required
          />
        </div>

        {/* Botões */}
        <div className="flex justify-between mt-6">
          <button
            type="button"
            onClick={handleClear}
            className="border border-blue-500 text-blue-500 rounded px-6 py-2 hover:bg-blue-50 transition"
          >
            Limpar
          </button>
          <button
            type="submit"
            className="bg-blue-600 text-white rounded px-6 py-2 flex items-center gap-2 hover:bg-blue-700 transition"
          >
            <FaPlus />
            Cadastrar
          </button>
        </div>
      </form>
    </div>
  )
}

export default ItemForm
