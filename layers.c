#include "layers.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void initAddBiome(int id, int tempCat, int biometype, float temp, float height)
{
    if(id & (~0xff)) return;
    biomes[id].id = id;
    biomes[id].type = biometype;
    biomes[id].temp = temp;
    biomes[id].height = height;
    biomes[id].tempCat = tempCat;
}

void createMutation(int id)
{
    biomes[id+128] = biomes[id];
    biomes[id+128].id = id+128;
}

/* initBiomes() has to be called before any of the generators can be used */
void initBiomes()
{
    int i;
    for(i = 0; i < 256; i++) biomes[i].id = none;

    const double hDefault = 0.1, hShallowWaters = -0.5, hOceans = -1.0, hDeepOceans = -1.8, hLowPlains = 0.125;
    const double hMidPlains = 0.2, hLowHills = 0.45, hHighPlateaus = 1.5, hMidHills = 1.0, hShores = 0.0;
    const double hRockyWaters = 0.1, hLowIslands = 0.2, hPartiallySubmerged = -0.2;

    initAddBiome(ocean, Oceanic, Ocean, 0.5, hOceans);
    initAddBiome(plains, Lush, Plains, 0.8, hDefault);
    initAddBiome(desert, Warm, Desert, 2.0, hLowPlains);
    initAddBiome(extremeHills, Lush, Hills, 0.2, hMidHills);
    initAddBiome(forest, Lush, Forest, 0.7, hDefault);
    initAddBiome(taiga, Lush, Taiga, 0.25, hMidPlains);
    initAddBiome(swampland, Lush, Swamp, 0.8, hPartiallySubmerged);
    initAddBiome(river, Lush, River, 0.5, hShallowWaters);
    initAddBiome(hell, Warm, Hell, 2.0, hDefault);
    initAddBiome(sky, Lush, Sky, 0.5, hDefault);
    initAddBiome(frozenOcean, Oceanic, Ocean, 0.0, hOceans);
    initAddBiome(frozenRiver, Cold, River, 0.0, hShallowWaters);
    initAddBiome(icePlains, Cold, Snow, 0.0, hLowPlains);
    initAddBiome(iceMountains, Cold, Snow, 0.0, hLowHills);
    initAddBiome(mushroomIsland, Lush, MushroomIsland, 0.9, hLowIslands);
    initAddBiome(mushroomIslandShore, Lush, MushroomIsland, 0.9, hShores);
    initAddBiome(beach, Lush, Beach, 0.8, hShores);
    initAddBiome(desertHills, Warm, Desert, 2.0, hLowHills);
    initAddBiome(forestHills, Lush, Forest, 0.7, hLowHills);
    initAddBiome(taigaHills, Lush, Taiga, 0.25, hLowHills);
    initAddBiome(extremeHillsEdge, Lush, Hills, 0.2, hMidHills);
    initAddBiome(jungle, Lush, Jungle, 0.95, hDefault);
    initAddBiome(jungleHills, Lush, Jungle, 0.95, hLowHills);
    initAddBiome(jungleEdge, Lush, Jungle, 0.95, hDefault);
    initAddBiome(deepOcean, Oceanic, Ocean, 0.5, hDeepOceans);
    initAddBiome(stoneBeach, Lush, StoneBeach, 0.2, hRockyWaters);
    initAddBiome(coldBeach, Cold, Beach, 0.05, hShores);
    initAddBiome(birchForest, Lush, Forest, 0.6, hDefault);
    initAddBiome(birchForestHills, Lush, Forest, 0.6, hLowHills);
    initAddBiome(roofedForest, Lush, Forest, 0.7, hDefault);
    initAddBiome(coldTaiga, Cold, Taiga, -0.5, hMidPlains);
    initAddBiome(coldTaigaHills, Cold, Taiga, -0.5, hLowHills);
    initAddBiome(megaTaiga, Lush, Taiga, 0.3, hMidPlains);
    initAddBiome(megaTaigaHills, Lush, Taiga, 0.3, hLowHills);
    initAddBiome(extremeHillsPlus, Lush, Hills, 0.2, hMidHills);
    initAddBiome(savanna, Warm, Savanna, 1.2, hLowPlains);
    initAddBiome(savannaPlateau, Warm, Savanna, 1.0, hHighPlateaus);
    initAddBiome(mesa, Warm, Mesa, 2.0, hDefault);
    initAddBiome(mesaPlateau_F, Warm, Mesa, 2.0, hHighPlateaus);
    initAddBiome(mesaPlateau, Warm, Mesa, 2.0, hHighPlateaus);

    // TODO: determine the 1.13 biome properties
    initAddBiome(skyIslandLow, Lush, Sky, 0, 0);
    initAddBiome(skyIslandMedium, Lush, Sky, 0, 0);
    initAddBiome(skyIslandHigh, Lush, Sky, 0, 0);
    initAddBiome(skyIslandBarren, Lush, Sky, 0, 0);
    initAddBiome(warmOcean, Oceanic, Ocean, 0, 0);
    initAddBiome(lukewarmOcean, Oceanic, Ocean, 0, 0);
    initAddBiome(coldOcean, Oceanic, Ocean, 0, 0);
    initAddBiome(warmDeepOcean, Oceanic, Ocean, 0, 0);
    initAddBiome(lukewarmDeepOcean, Oceanic, Ocean, 0, 0);
    initAddBiome(coldDeepOcean, Oceanic, Ocean, 0, 0);
    initAddBiome(frozenDeepOcean, Oceanic, Ocean, 0, 0);

    createMutation(plains);
    createMutation(desert);
    createMutation(extremeHills);
    createMutation(forest);
    createMutation(taiga);
    createMutation(swampland);
    createMutation(icePlains);
    createMutation(jungle);
    createMutation(jungleEdge);
    createMutation(birchForest);
    createMutation(birchForestHills);
    createMutation(roofedForest);
    createMutation(coldTaiga);
    createMutation(megaTaiga);
    createMutation(megaTaigaHills);
    createMutation(extremeHillsPlus);
    createMutation(savanna);
    createMutation(savannaPlateau);
    createMutation(mesa);
    createMutation(mesaPlateau_F);
    createMutation(mesaPlateau);
}


void setWorldSeed(Layer *layer, long seed)
{
    if(layer->p2 != NULL && layer->getMap != mapHills)
        setWorldSeed(layer->p2, seed);

    if(layer->p != NULL)
        setWorldSeed(layer->p, seed);

    layer->worldSeed = seed;
    layer->worldSeed *= layer->worldSeed * 6364136223846793005L + 1442695040888963407L;
    layer->worldSeed += layer->baseSeed;
    layer->worldSeed *= layer->worldSeed * 6364136223846793005L + 1442695040888963407L;
    layer->worldSeed += layer->baseSeed;
    layer->worldSeed *= layer->worldSeed * 6364136223846793005L + 1442695040888963407L;
    layer->worldSeed += layer->baseSeed;
}


void mapNull(Layer *l, int * __restrict out, int x, int z, int w, int h)
{
}


void mapIsland(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    register int x, z;
    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            setChunkSeed(l, (long)(areaX + x), (long)(areaZ + z));
            out[x + z*areaWidth] = mcNextInt(l, 10) == 0 ? 1 : 0;
        }
    }

    if(areaX > -areaWidth && areaX <= 0 && areaZ > -areaHeight && areaZ <= 0)
    {
        out[-areaX + -areaZ * areaWidth] = 1;
    }
}


void mapZoom(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX >> 1;
    int pZ = areaZ >> 1;
    int pWidth =  (areaWidth >> 1) + 2;
    int pHeight = (areaHeight >> 1) + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    int (*selectRand)(Layer *l, int a1, int a2, int a3, int a4) = (l->p->getMap == mapIsland) ? selectRandom4 : selectModeOrRandom;

    int newWidth = (pWidth-1) << 1;
    int newHeight = (pHeight-1) << 1;
    int idx, a, b;
    int *buf = (int *)malloc((newWidth+1)*(newHeight+1)*sizeof(*buf));

    for(z = 0; z < pHeight - 1; z++)
    {
        idx = (z << 1) * newWidth;
        a = out[(z+0)*pWidth];
        b = out[(z+1)*pWidth];

        for(x = 0; x < pWidth - 1; x++)
        {
            setChunkSeed(l, (long)((x + pX) << 1), (long)((z + pZ) << 1));
            int a1 = out[x+1 + (z+0)*pWidth];
            int b1 = out[x+1 + (z+1)*pWidth];
            buf[idx] = a;
            buf[idx + newWidth] = selectRandom2(l, a, b);
            idx++;
            buf[idx] = selectRandom2(l, a, a1);
            buf[idx + newWidth] = selectRand(l, a, a1, b, b1);
            idx++;
            a = a1;
            b = b1;
        }
    }

    for(z = 0; z < areaHeight; z++)
    {
        memcpy(&out[z*areaWidth], &buf[(z + (areaZ & 1))*newWidth + (areaX & 1)], areaWidth*sizeof(int));
    }

    free(buf);
}


void mapAddIsland(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int v00 = out[x+0 + (z+0)*pWidth];
            int v20 = out[x+2 + (z+0)*pWidth];
            int v02 = out[x+0 + (z+2)*pWidth];
            int v22 = out[x+2 + (z+2)*pWidth];
            int v11 = out[x+1 + (z+1)*pWidth];

            if(v11 == 0 && (v00 != 0 || v20 != 0 || v02 != 0 || v22 != 0))
            {
                setChunkSeed(l, (long)(x + areaX), (long)(z + areaZ));

                int v = 1;
                int inc = 1;

                if(v00 != 0 && mcNextInt(l, inc++) == 0) v = v00;
                if(v20 != 0 && mcNextInt(l, inc++) == 0) v = v20;
                if(v02 != 0 && mcNextInt(l, inc++) == 0) v = v02;
                if(v22 != 0 && mcNextInt(l, inc++) == 0) v = v22;

                if(mcNextInt(l, 3) == 0)
                    out[x + z*areaWidth] = v;
                else if(v == 4)
                    out[x + z*areaWidth] = 4;
                else
                    out[x + z*areaWidth] = 0;
            }
            else if(v11 > 0 && (v00 == 0 || v20 == 0 || v02 == 0 || v22 == 0))
            {
                setChunkSeed(l, (long)(x + areaX), (long)(z + areaZ));

                if(mcNextInt(l, 5) == 0)
                    out[x + z*areaWidth] = (v11 == 4) ? 4 : 0;
                else
                    out[x + z*areaWidth] = v11;
            }
            else
            {
                out[x + z*areaWidth] = v11;
            }
        }
    }
}


void mapRemoveTooMuchOcean(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int v11 = out[x+1 + (z+1)*pWidth];
            out[x + z*areaWidth] = v11;

            if(out[x+1 + (z+0)*pWidth] != 0) continue;
            if(out[x+2 + (z+1)*pWidth] != 0) continue;
            if(out[x+0 + (z+1)*pWidth] != 0) continue;
            if(out[x+1 + (z+2)*pWidth] != 0) continue;

            if(v11 == 0)
            {
                setChunkSeed(l, (long)(x + areaX), (long)(z + areaZ));

                if(mcNextInt(l, 2) == 0)
                {
                    out[x + z*areaWidth] = 1;
                }
            }
        }
    }
}


void mapAddSnow(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);
    
    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int v11 = out[x+1 + (z+1)*pWidth];

            if(isShallowOcean(v11))
            {
                out[x + z*areaWidth] = v11;
            }
            else
            {
                setChunkSeed(l, (long)(x + areaX), (long)(z + areaZ));
                int r = mcNextInt(l, 6);
                int v;

                if(r == 0)      v = 4;
                else if(r <= 1) v = 3;
                else            v = 1;

                out[x + z*areaWidth] = v;
            }
        }
    }
}




void mapCoolWarm(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int v11 = out[x+1 + (z+1)*pWidth];

            if(v11 == 1)
            {
                int v10 = out[x+1 + (z+0)*pWidth];
                int v21 = out[x+2 + (z+1)*pWidth];
                int v01 = out[x+0 + (z+1)*pWidth];
                int v12 = out[x+1 + (z+2)*pWidth];

                if(v10 == 3 || v10 == 4 || v21 == 3 || v21 == 4 || v01 == 3 || v01 == 4 || v12 == 3 || v12 == 4)
                {
                    v11 = 2;
                }
            }

            out[x + z*areaWidth] = v11;
        }
    }
}


void mapHeatIce(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int v11 = out[x+1 + (z+1)*pWidth];

            if(v11 == 4)
            {
                int v10 = out[x+1 + (z+0)*pWidth];
                int v21 = out[x+2 + (z+1)*pWidth];
                int v01 = out[x+0 + (z+1)*pWidth];
                int v12 = out[x+1 + (z+2)*pWidth];

                if(v10 == 1 || v10 == 2 || v21 == 1 || v21 == 2 || v01 == 1 || v01 == 2 || v12 == 1 || v12 == 2)
                {
                    v11 = 3;
                }
            }

            out[x + z*areaWidth] = v11;
        }
    }
}


void mapSpecial(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    l->p->getMap(l->p, out, areaX, areaZ, areaWidth, areaHeight);

    int x, z;
    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int v = out[x + z*areaWidth];
            if(v == 0) continue;

            setChunkSeed(l, (long)(x + areaX), (long)(z + areaZ));

            if(mcNextInt(l, 13) == 0)
            {
                v |= (1 + mcNextInt(l, 15)) << 8 & 0xf00;
                // 1 to 1 mapping so 'out' can be overwritten immediately
                out[x + z*areaWidth] = v;
            }
        }
    }
}


void mapAddMushroomIsland(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int v11 = out[x+1 + (z+1)*pWidth];

            // surrounded by ocean?
            if(v11 == 0 && !out[x+0 + (z+0)*pWidth] && !out[x+2 + (z+0)*pWidth] && !out[x+0 + (z+2)*pWidth] && !out[x+2 + (z+2)*pWidth])
            {
                setChunkSeed(l, (long)(x + areaX), (long)(z + areaZ));
                if(mcNextInt(l, 100) == 0) {
                    out[x + z*areaWidth] = mushroomIsland;
                    continue;
                }
            }

            out[x + z*areaWidth] = v11;
        }
    }
}


void mapDeepOcean(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int v11 = out[(x+1) + (z+1)*pWidth];

            if(isShallowOcean(v11))
            {
                // count adjacent oceans
                int oceans = 0;
                if(isShallowOcean(out[(x+1) + (z+0)*pWidth])) oceans++;
                if(isShallowOcean(out[(x+2) + (z+1)*pWidth])) oceans++;
                if(isShallowOcean(out[(x+0) + (z+1)*pWidth])) oceans++;
                if(isShallowOcean(out[(x+1) + (z+2)*pWidth])) oceans++;

                if(oceans > 3)
                {
                    if(v11 == warmOcean)
                        v11 = warmDeepOcean;
                    else if(v11 == lukewarmOcean)
                        v11 = lukewarmDeepOcean;
                    else if(v11 == ocean)
                        v11 = deepOcean;
                    else if(v11 == coldOcean)
                        v11 = coldDeepOcean;
                    else if(v11 == frozenOcean)
                        v11 = frozenDeepOcean;
                    else
                        v11 = deepOcean;
                }
            }

            out[x + z*areaWidth] = v11;
        }
    }
}


const int warmBiomes[] = {desert, desert, desert, savanna, savanna, plains};
const int lushBiomes[] = {forest, roofedForest, extremeHills, plains, birchForest, swampland};
const int coldBiomes[] = {forest, extremeHills, taiga, plains};
const int snowBiomes[] = {icePlains, icePlains, icePlains, coldTaiga};

void mapBiome(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    l->p->getMap(l->p, out, areaX, areaZ, areaWidth, areaHeight);

    int x, z;
    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int idx = x + z*areaWidth;
            int id = out[idx];
            int hasHighBit = (id & 0xf00) >> 8;
            id &= -0xf01;

            if(getBiomeType(id) == Ocean || id == mushroomIsland)
            {
                out[idx] = id;
                continue;
            }

            setChunkSeed(l, (long)(x + areaX), (long)(z + areaZ));

            switch(id){
            case Warm:
                if(hasHighBit) out[idx] = (mcNextInt(l, 3) == 0) ? mesaPlateau : mesaPlateau_F;
                else out[idx] = warmBiomes[mcNextInt(l, 6)];
                break;
            case Lush:
                if(hasHighBit) out[idx] = jungle;
                else out[idx] = lushBiomes[mcNextInt(l, 6)];
                break;
            case Cold:
                if(hasHighBit) out[idx] = megaTaiga;
                else out[idx] = coldBiomes[mcNextInt(l, 4)];
                break;
            case Freezing:
                out[idx] = snowBiomes[mcNextInt(l, 4)];
                break;
            default:
                out[idx] = mushroomIsland;
            }
        }
    }
}


void mapRiverInit(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    l->p->getMap(l->p, out, areaX, areaZ, areaWidth, areaHeight);

    int x, z;
    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            if(out[x + z*areaWidth] > 0)
            {
                setChunkSeed(l, (long)(x + areaX), (long)(z + areaZ));
                out[x + z*areaWidth] = mcNextInt(l, 299999)+2;
            }
            else
            {
                out[x + z*areaWidth] = 0;
            }
        }
    }
}


// replaceEdgeIfNecessary() always returns 0 in the only place it is used in
// Minecraft, making it redundant.
/*
static inline int replaceEdgeIfNecessary(int *out, int idx, int v10, int v21, int v01, int v12, int id, int baseID, int edgeID)
{
    if(!equalOrPlateau(id, baseID)) return 0;

    if(canBeNeighbors(v10, baseID) && canBeNeighbors(v21, baseID) && canBeNeighbors(v01, baseID) && canBeNeighbors(v12, baseID))
        out[idx] = id;
    else
        out[idx] = edgeID;

    return 1;
}
*/

static inline int replaceEdge(int *out, int idx, int v10, int v21, int v01, int v12, int id, int baseID, int edgeID)
{
    if(id != baseID) return 0;

    if(equalOrPlateau(v10, baseID) && equalOrPlateau(v21, baseID) && equalOrPlateau(v01, baseID) && equalOrPlateau(v12, baseID))
        out[idx] = id;
    else
        out[idx] = edgeID;

    return 1;
}

void mapBiomeEdge(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int v11 = out[x+1 + (z+1)*pWidth];

            int v10 = out[x+1 + (z+0)*pWidth];
            int v21 = out[x+2 + (z+1)*pWidth];
            int v01 = out[x+0 + (z+1)*pWidth];
            int v12 = out[x+1 + (z+2)*pWidth];

            if(/*!replaceEdgeIfNecessary(out, x + z*areaWidth, v10, v21, v01, v12, v11, extremeHills, extremeHillsEdge) &&*/
               !replaceEdge(out, x + z*areaWidth, v10, v21, v01, v12, v11, mesaPlateau_F, mesa) &&
               !replaceEdge(out, x + z*areaWidth, v10, v21, v01, v12, v11, mesaPlateau, mesa) &&
               !replaceEdge(out, x + z*areaWidth, v10, v21, v01, v12, v11, megaTaiga, taiga))
            {
                if(v11 == desert)
                {
                    if(v10 != icePlains && v21 != icePlains && v01 != icePlains && v12 != icePlains)
                    {
                        out[x + z*areaWidth] = v11;
                    }
                    else
                    {
                        out[x + z*areaWidth] = extremeHillsPlus;
                    }
                }
                else if(v11 == swampland)
                {
                    if(v10 != desert && v21 != desert && v01 != desert && v12 != desert &&
                       v10 != coldTaiga && v21 != coldTaiga && v01 != coldTaiga && v12 != coldTaiga &&
                       v10 != icePlains && v21 != icePlains && v01 != icePlains && v12 != icePlains)
                    {
                        if(v10 != jungle && v12 != jungle && v21 != jungle && v01 != jungle)
                            out[x + z*areaWidth] = v11;
                        else
                            out[x + z*areaWidth] = jungleEdge;
                    }
                    else
                    {
                        out[x + z*areaWidth] = plains;
                    }
                }
                else
                {
                    out[x + z*areaWidth] = v11;
                }
            }
        }
    }
}


void mapHills(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;
    static int bufsize = 0;
    static int *buf = NULL;

    if(l->p2 == NULL)
    {
        printf("mapHills() requires two parents! Use setupMultiLayer()\n");
        exit(1);
    }

    if(bufsize < pWidth*pHeight)
    {
        if(buf != NULL) free(buf);

        bufsize = pWidth*pHeight;
        buf = (int*)malloc(bufsize*sizeof(int));
    }

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);
    memcpy(buf, out, pWidth*pHeight*sizeof(int));

    l->p2->getMap(l->p2, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            setChunkSeed(l, (long)(x + areaX), (long)(z + areaZ));
            int a11 = buf[x+1 + (z+1)*pWidth]; // biome branch
            int b11 = out[x+1 + (z+1)*pWidth]; // river branch
            int idx = x + z*areaWidth;

            int var12 = (b11 - 2) % 29 == 0;

            if(a11 != 0 && b11 >= 2 && (b11 - 2) % 29 == 1 && a11 < 128)
            {
                out[idx] = (biomeExists(a11 + 128)) ? a11 + 128 : a11;
            }
            else if(mcNextInt(l, 3) != 0 && !var12)
            {
                out[idx] = a11;
            }
            else
            {
                int hillID = a11;

                switch(a11){
                case desert:
                    hillID = desertHills; break;
                case forest:
                    hillID = forestHills; break;
                case birchForest:
                    hillID = birchForestHills; break;
                case roofedForest:
                    hillID = plains; break;
                case taiga:
                    hillID = taigaHills; break;
                case megaTaiga:
                    hillID = megaTaigaHills; break;
                case coldTaiga:
                    hillID = coldTaigaHills; break;
                case plains:
                    hillID = (mcNextInt(l, 3) == 0) ? forestHills : forest; break;
                case icePlains:
                    hillID = iceMountains; break;
                case jungle:
                    hillID = jungleHills; break;
                case ocean:
                    hillID = deepOcean; break;
                case extremeHills:
                    hillID = extremeHillsPlus; break;
                case savanna:
                    hillID = savannaPlateau; break;
                default:
                    if(equalOrPlateau(a11, mesaPlateau_F))
                        hillID = mesa;
                    else if(a11 == deepOcean && mcNextInt(l, 3) == 0)
                        hillID = (mcNextInt(l, 2) == 0) ? plains : forest;
                    break;
                }

                if(var12 && hillID != a11)
                {
                    if(biomeExists(hillID + 128))
                        hillID += 128;
                    else
                        hillID = a11;
                }

                if(hillID == a11)
                {
                    out[idx] = a11;
                }
                else
                {
                    int a10 = buf[x+1 + (z+0)*pWidth];
                    int a21 = buf[x+2 + (z+1)*pWidth];
                    int a01 = buf[x+0 + (z+1)*pWidth];
                    int a12 = buf[x+1 + (z+2)*pWidth];
                    int equals = 0;

                    if(equalOrPlateau(a10, a11)) equals++;
                    if(equalOrPlateau(a21, a11)) equals++;
                    if(equalOrPlateau(a01, a11)) equals++;
                    if(equalOrPlateau(a12, a11)) equals++;

                    if(equals >= 3)
                        out[idx] = hillID;
                    else
                        out[idx] = a11;
                }
            }
        }
    }
}


static inline int reduceID(int id)
{
    return id >= 2 ? 2 + (id & 1) : id;
}

void mapRiver(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int v01 = reduceID(out[x+0 + (z+1)*pWidth]);
            int v21 = reduceID(out[x+2 + (z+1)*pWidth]);
            int v10 = reduceID(out[x+1 + (z+0)*pWidth]);
            int v12 = reduceID(out[x+1 + (z+2)*pWidth]);
            int v11 = reduceID(out[x+1 + (z+1)*pWidth]);

            if (v11 == v01 && v11 == v10 && v11 == v21 && v11 == v12)
            {
                out[x + z * areaWidth] = -1;
            }
            else
            {
                out[x + z * areaWidth] = river;
            }
        }
    }
}


void mapSmooth(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int v11 = out[x+1 + (z+1)*pWidth];
            int v10 = out[x+1 + (z+0)*pWidth];
            int v21 = out[x+2 + (z+1)*pWidth];
            int v01 = out[x+0 + (z+1)*pWidth];
            int v12 = out[x+1 + (z+2)*pWidth];

            if(v01 == v21 && v10 == v12)
            {
                setChunkSeed(l, (long)(x + areaX), (long)(z + areaZ));

                if(mcNextInt(l, 2) == 0)
                    v11 = v01;
                else
                    v11 = v10;
            }
            else
            {
                if(v01 == v21) v11 = v01;
                if(v10 == v12) v11 = v10;
            }

            out[x + z * areaWidth] = v11;
        }
    }
}


void mapRareBiome(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            setChunkSeed(l, (long)(x + areaX), (long)(z + areaZ));
            int v11 = out[x+1 + (z+1)*pWidth];

            if(mcNextInt(l, 57) == 0 && v11 == plains)
            {
                // Flower Forest
                out[x + z*areaWidth] = plains + 128;
            }
            else
            {
                out[x + z*areaWidth] = v11;
            }
        }
    }
}


inline static int replaceOcean(int *out, int idx, int v10, int v21, int v01, int v12, int id, int replaceID)
{
    if(isOceanic(id)) return 0;

    if(!isOceanic(v10) && !isOceanic(v21) && !isOceanic(v01) && !isOceanic(v12))
        out[idx] = id;
    else
        out[idx] = replaceID;

    return 1;
}

inline static int isBiomeJFTO(int id)
{
    return biomeExists(id) && (getBiomeType(id) == Jungle || id == forest || id == taiga || isOceanic(id));
}

void mapShore(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int v11 = out[x+1 + (z+1)*pWidth];
            int v10 = out[x+1 + (z+0)*pWidth];
            int v21 = out[x+2 + (z+1)*pWidth];
            int v01 = out[x+0 + (z+1)*pWidth];
            int v12 = out[x+1 + (z+2)*pWidth];

            int biome = biomeExists(v11) ? v11 : 0;

            if(v11 == mushroomIsland)
            {
                if(v10 != ocean && v21 != ocean && v01 != ocean && v12 != ocean)
                    out[x + z*areaWidth] = v11;
                else
                    out[x + z*areaWidth] = mushroomIslandShore;
            }
            else if(/*biome < 128 &&*/ getBiomeType(biome) == Jungle)
            {
                if(isBiomeJFTO(v10) && isBiomeJFTO(v21) && isBiomeJFTO(v01) && isBiomeJFTO(v12))
                {
                    if (!isOceanic(v10) && !isOceanic(v21) && !isOceanic(v01) && !isOceanic(v12))
                        out[x + z*areaWidth] = v11;
                    else
                        out[x + z*areaWidth] = beach;
                }
                else
                {
                    out[x + z*areaWidth] = jungleEdge;
                }
            }
            else if (v11 != extremeHills && v11 != extremeHillsPlus && v11 != extremeHillsEdge)
            {
                if(isBiomeSnowy(biome))
                {
                    replaceOcean(out, x + z*areaWidth, v10, v21, v01, v12, v11, coldBeach);
                }
                else if(v11 != mesa && v11 != mesaPlateau_F)
                {
                    if(v11 != ocean && v11 != deepOcean && v11 != river && v11 != swampland)
                    {
                        if(!isOceanic(v10) && !isOceanic(v21) && !isOceanic(v01) && !isOceanic(v12))
                            out[x + z*areaWidth] = v11;
                        else
                            out[x + z*areaWidth] = beach;
                    }
                    else
                    {
                        out[x + z*areaWidth] = v11;
                    }
                }
                else
                {
                    if(!isOceanic(v10) && !isOceanic(v21) && !isOceanic(v01) && !isOceanic(v12))
                    {
                        if(getBiomeType(v10) == Mesa && getBiomeType(v21) == Mesa && getBiomeType(v01) == Mesa && getBiomeType(v12) == Mesa)
                            out[x + z*areaWidth] = v11;
                        else
                            out[x + z*areaWidth] = desert;
                    }
                    else
                    {
                        out[x + z*areaWidth] = v11;
                    }
                }
            }
            else
            {
                replaceOcean(out, x + z*areaWidth, v10, v21, v01, v12, v11, stoneBeach);
            }
        }
    }
}


void mapRiverMix(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int idx;
    int *buf = (int*)malloc(areaWidth*areaHeight*sizeof(int));

    if(l->p2 == NULL)
    {
        printf("mapRiverMix() requires two parents! Use setupMultiLayer()\n");
        exit(1);
    }

    l->p->getMap(l->p, out, areaX, areaZ, areaWidth, areaHeight); // biome chain
    memcpy(buf, out, areaWidth*areaHeight*sizeof(int));

    l->p2->getMap(l->p2, out, areaX, areaZ, areaWidth, areaHeight); // rivers

    for(idx = 0; idx < areaHeight*areaWidth; idx++)
    {
        if(isOceanic(buf[idx]))
        {
            out[idx] = buf[idx];
        }
        else
        {
            if(out[idx] == river)
            {
                if(buf[idx] == icePlains)
                    out[idx] = frozenRiver;
                else if(buf[idx] == mushroomIsland || buf[idx] == mushroomIslandShore)
                    out[idx] = mushroomIslandShore;
                else
                    out[idx] = out[idx] & 255;
            }
            else
            {
                out[idx] = buf[idx];
            }
        }
    }

    free(buf);
}



void mapOceanTemp(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    // The new ocean branch doesn't actually depend on previous layers.

    //int pX = areaX - 1;
    //int pZ = areaZ - 1;
    //int pWidth = areaWidth + 2;
    //int pHeight = areaHeight + 2;
    int x, z;

    //l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            setChunkSeed(l, (long)(x + areaX), (long)(z + areaZ));

            int v11;

            float tmp = (float)mcNextInt(l, 100) / 100.0f;

            if(tmp < 0.05f)
                v11 = warmOcean;
            else if(tmp < 0.4f)
                v11 = lukewarmOcean;
            else if(tmp < 0.675f)
                v11 = ocean;
            else if(tmp < 0.95f)
                v11 = coldOcean;
            else if(tmp < 1.0f)
                v11 = frozenOcean;
            else
                v11 = ocean;

            out[x + z*areaWidth] = v11;
        }
    }
}

void mapEdgeOcean(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int pX = areaX - 1;
    int pZ = areaZ - 1;
    int pWidth = areaWidth + 2;
    int pHeight = areaHeight + 2;
    int x, z;

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < areaHeight; z++)
    {
        for(x = 0; x < areaWidth; x++)
        {
            int v11 = out[x+1 + (z+1)*pWidth];

            if(v11 == warmOcean)
            {
                int v10 = out[x+1 + (z+0)*pWidth];
                int v21 = out[x+2 + (z+1)*pWidth];
                int v01 = out[x+0 + (z+1)*pWidth];
                int v12 = out[x+1 + (z+2)*pWidth];

                if(v10 == frozenOcean || v21 == frozenOcean || v01 == frozenOcean || v12 == frozenOcean)
                {
                    v11 = ocean;
                }
            }

            if(v11 == frozenOcean)
            {
                int v10 = out[x+1 + (z+0)*pWidth];
                int v21 = out[x+2 + (z+1)*pWidth];
                int v01 = out[x+0 + (z+1)*pWidth];
                int v12 = out[x+1 + (z+2)*pWidth];

                if(v10 == warmOcean || v21 == warmOcean || v01 == warmOcean || v12 == warmOcean)
                {
                    v11 = ocean;
                }
            }

            out[x + z*areaWidth] = v11;
        }
    }
}


void mapOceanMix(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    int idx;
    int *buf = (int*)malloc(areaWidth*areaHeight*sizeof(int));

    if(l->p2 == NULL)
    {
        printf("mapOceanMix() requires two parents! Use setupMultiLayer()\n");
        exit(1);
    }

    l->p->getMap(l->p, out, areaX, areaZ, areaWidth, areaHeight);
    memcpy(buf, out, areaWidth*areaHeight*sizeof(int));

    l->p2->getMap(l->p2, out, areaX, areaZ, areaWidth, areaHeight);

    for(idx = 0; idx < areaHeight*areaWidth; idx++)
    {
        if(!isOceanic(buf[idx]) || !isOceanic(out[idx]))
        {
            out[idx] = buf[idx];
        }
        else if(buf[idx] == deepOcean)
        {
            if(out[idx] == lukewarmOcean)
                out[idx] = lukewarmDeepOcean;
            else if(out[idx] == ocean)
                out[idx] = deepOcean;
            else if(out[idx] == coldOcean)
                out[idx] = coldDeepOcean;
            else if(out[idx] == frozenOcean)
                out[idx] = frozenDeepOcean;
        }
    }

    free(buf);
}





void mapVoronoiZoom(Layer *l, int * __restrict out, int areaX, int areaZ, int areaWidth, int areaHeight)
{
    areaX -= 2;
    areaZ -= 2;
    int pX = areaX >> 2;
    int pZ = areaZ >> 2;
    int pWidth = (areaWidth >> 2) + 2;
    int pHeight = (areaHeight >> 2) + 2;
    int newWidth = (pWidth-1) << 2;
    int newHeight = (pHeight-1) << 2;
    int x, z, i, j;
    int *buf = (int *)malloc((newWidth+1)*(newHeight+1)*sizeof(*buf));

    l->p->getMap(l->p, out, pX, pZ, pWidth, pHeight);

    for(z = 0; z < pHeight - 1; z++)
    {
        int v00 = out[(z+0)*pWidth];
        int v01 = out[(z+1)*pWidth];

        for(x = 0; x < pWidth - 1; x++)
        {
            setChunkSeed(l, (x+pX) << 2, (z+pZ) << 2);
            double da1 = (mcNextInt(l, 1024) / 1024.0 - 0.5) * 3.6;
            double da2 = (mcNextInt(l, 1024) / 1024.0 - 0.5) * 3.6;

            setChunkSeed(l, (x+pX+1) << 2, (z+pZ) << 2);
            double db1 = (mcNextInt(l, 1024) / 1024.0 - 0.5) * 3.6 + 4.0;
            double db2 = (mcNextInt(l, 1024) / 1024.0 - 0.5) * 3.6;

            setChunkSeed(l, (x+pX) << 2, (z+pZ+1) << 2);
            double dc1 = (mcNextInt(l, 1024) / 1024.0 - 0.5) * 3.6;
            double dc2 = (mcNextInt(l, 1024) / 1024.0 - 0.5) * 3.6 + 4.0;

            setChunkSeed(l, (x+pX+1) << 2, (z+pZ+1) << 2);
            double dd1 = (mcNextInt(l, 1024) / 1024.0 - 0.5) * 3.6 + 4.0;
            double dd2 = (mcNextInt(l, 1024) / 1024.0 - 0.5) * 3.6 + 4.0;

            int v10 = out[x+1 + (z+0)*pWidth] & 255;
            int v11 = out[x+1 + (z+1)*pWidth] & 255;

            for(j = 0; j < 4; j++)
            {
                int idx = ((z << 2) + j) * newWidth + (x << 2);

                for(i = 0; i < 4; i++)
                {
                    double da = (j-da2)*(j-da2) + (i-da1)*(i-da1);
                    double db = (j-db2)*(j-db2) + (i-db1)*(i-db1);
                    double dc = (j-dc2)*(j-dc2) + (i-dc1)*(i-dc1);
                    double dd = (j-dd2)*(j-dd2) + (i-dd1)*(i-dd1);

                    if (da < db && da < dc && da < dd)
                    {
                        buf[idx++] = v00;
                    }
                    else if (db < da && db < dc && db < dd)
                    {
                        buf[idx++] = v10;
                    }
                    else if (dc < da && dc < db && dc < dd)
                    {
                        buf[idx++] = v01;
                    }
                    else
                    {
                        buf[idx++] = v11;
                    }
                }
            }

            v00 = v10;
            v01 = v11;
        }
    }

    for(z = 0; z < areaHeight; z++)
    {
        memcpy(&out[z * areaWidth], &buf[(z + (areaZ & 3))*newWidth + (areaX & 3)], areaWidth*sizeof(int));
    }

    free(buf);
}


