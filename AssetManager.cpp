/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AssetManager.h"
#include <assert.h>


AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager(){
    assert(sInstance == nullptr);
    sInstance = this;
}

sf::Texture& AssetManager::GetTexture(const std::string& filename){
    
    auto& texMap = sInstance->m_Textures;
    auto pairFound = texMap.find(filename);
    
    if(pairFound != texMap.end()){
        return pairFound->second;
    }
    else{
        auto& texture = texMap[filename];
        texture.loadFromFile(filename);
        return texture;
    }
}