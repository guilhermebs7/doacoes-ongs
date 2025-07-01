import type { NextConfig } from 'next';

const nextConfig: NextConfig = {
  swcMinify: true,

  experimental: {
    swcPlugins: [],
  },
};

export default nextConfig;
