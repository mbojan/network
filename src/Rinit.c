/*
######################################################################
#
# utils.c
#
# Written by Jeffrey Horner <jeffrey.horner@gmail.com>
# Last Modified 5/07/2016
# Licensed under the GNU General Public License version 2 (June, 1991)
# or greater
#
# Part of the R/network package
#
# This file contains the R/C initialization code
#
######################################################################
*/

#include <R.h>            
#include <Rinternals.h>            
#include <R_ext/Rdynload.h>
#include "access.h"
#include "constructors.h"
#include "layout.h"
#include "utils.h"

#define CALLDEF(name, n) {#name,(DL_FUNC) &name, n}
static R_CallMethodDef CallEntries[] = {
  CALLDEF(addEdge_R,6),
  CALLDEF(addEdges_R,6),
  CALLDEF(addVertices_R,3),
  CALLDEF(copyNetwork_R,1),
  CALLDEF(deleteEdgeAttribute_R,2),
  CALLDEF(deleteEdges_R,2),
  CALLDEF(getEdgeAttribute_R,5),
  CALLDEF(deleteNetworkAttribute_R,2),
  CALLDEF(deleteVertexAttribute_R,2),
  CALLDEF(deleteVertices_R,2),
  CALLDEF(getEdgeIDs_R,5),
  CALLDEF(getEdges_R,5),
  CALLDEF(getNeighborhood_R,4),
  CALLDEF(isAdjacent_R,4),
  CALLDEF(isNANetwork_R,2),
  CALLDEF(networkEdgecount_R,2),
  CALLDEF(permuteVertexIDs_R,2),
  CALLDEF(setEdgeAttribute_R,4),
  CALLDEF(setEdgeAttributes_R,4),
  CALLDEF(setEdgeValue_R,4),
  CALLDEF(setNetworkAttribute_R,3),
  CALLDEF(setVertexAttribute_R,4),
  CALLDEF(setVertexAttributes_R,4),
  CALLDEF(nonEmptyEdges_R,1),
  {NULL,NULL,0}
};

static R_CMethodDef CEntries[] = {
  CALLDEF(network_layout_fruchtermanreingold_R,15),
  CALLDEF(network_layout_kamadakawai_R,10),
  {NULL,NULL,0}
};

void R_init_network(DllInfo *dll)
{
   R_registerRoutines(dll,CEntries,CallEntries, NULL, NULL);
   R_useDynamicSymbols(dll, FALSE);

 
  /*Add back the various things required by the API.*/

  /*Register access routines*/
  R_RegisterCCallable("network", "getEdgeAttribute", (DL_FUNC) getEdgeAttribute);
  R_RegisterCCallable("network", "getEdgeIDs", (DL_FUNC) getEdgeIDs);
  R_RegisterCCallable("network", "getEdges", (DL_FUNC) getEdges);
  R_RegisterCCallable("network", "getNeighborhood", (DL_FUNC) getNeighborhood);
  R_RegisterCCallable("network", "getNetworkAttribute", (DL_FUNC) getNetworkAttribute);
  R_RegisterCCallable("network", "hasLoops", (DL_FUNC) hasLoops);
  R_RegisterCCallable("network", "isAdjacent", (DL_FUNC) isAdjacent);
  R_RegisterCCallable("network", "isDirected", (DL_FUNC) isDirected);
  R_RegisterCCallable("network", "isHyper", (DL_FUNC) isHyper);
  R_RegisterCCallable("network", "isLoop", (DL_FUNC) isLoop);
  R_RegisterCCallable("network", "isMultiplex", (DL_FUNC) isMultiplex);
  R_RegisterCCallable("network", "isNetwork", (DL_FUNC) isNetwork);
  R_RegisterCCallable("network", "networkEdgecount", (DL_FUNC) networkEdgecount);
  R_RegisterCCallable("network", "networkSize", (DL_FUNC) networkSize);

  /*Register modification routines*/
  R_RegisterCCallable("network", "addEdge_R", (DL_FUNC) addEdge_R);
  R_RegisterCCallable("network", "addEdges_R", (DL_FUNC) addEdges_R);
  R_RegisterCCallable("network", "deleteEdgeAttribute", (DL_FUNC) deleteEdgeAttribute);
  R_RegisterCCallable("network", "deleteNetworkAttribute", (DL_FUNC) deleteNetworkAttribute);
  R_RegisterCCallable("network", "deleteVertexAttribute", (DL_FUNC) deleteVertexAttribute);
  R_RegisterCCallable("network", "setNetworkAttribute", (DL_FUNC) setNetworkAttribute);
  R_RegisterCCallable("network", "setVertexAttribute", (DL_FUNC) setVertexAttribute);

  /* Callable functions from other packages' C code */
#define RREGDEF(name) R_RegisterCCallable("network", #name, (DL_FUNC) name)
   RREGDEF(setListElement);
   RREGDEF(getListElement);
}
