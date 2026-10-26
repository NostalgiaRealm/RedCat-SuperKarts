/*
 * FUN_00495fe0 at 00495fe0
 * undefined FUN_00495fe0(void)
 * Address ranges: 00495fe0-00496287
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_00495fe0(int *param_1,float *param_2,undefined4 param_3,undefined4 param_4,int *param_5,
            undefined4 *param_6,int *param_7)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = 0;
  iVar1 = param_1[1];
  iVar4 = *param_1;
  local_c = param_2;
  local_8 = 0;
  local_4 = param_4;
  if (iVar4 < iVar1) {
    param_2 = (float *)(param_1 + 0x62);
    do {
      local_18 = FUN_00496870(iVar4,0);
      local_14 = FUN_00496870(iVar4,1);
      local_10 = FUN_00496870(iVar4,2);
      cVar2 = FUN_00495ed0(local_c,local_8,local_4,&local_18);
      if ((cVar2 == '\x01') && (0.4 < *param_2)) {
        *param_5 = iVar4;
        *param_6 = 1;
        *param_7 = iVar3;
        return;
      }
      iVar4 = iVar4 + 3;
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 3;
    } while (iVar4 < iVar1);
  }
  iVar1 = param_1[3];
  iVar4 = param_1[2];
  iVar3 = 0;
  if (iVar4 < iVar1) {
    param_2 = (float *)(param_1 + 0xe2);
    do {
      local_18 = FUN_004967c0(iVar4,0);
      local_14 = FUN_004967c0(iVar4,1);
      local_10 = FUN_004967c0(iVar4,2);
      cVar2 = FUN_00495ed0(local_c,local_8,local_4,&local_18);
      if ((cVar2 == '\x01') && (0.4 < *param_2)) {
        *param_5 = iVar4;
        *param_6 = 0;
        *param_7 = iVar3;
        FUN_004afce0(s_Found_road_plane___d__d_004fb120,*param_5,iVar3);
        return;
      }
      iVar4 = iVar4 + 3;
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 3;
    } while (iVar4 < iVar1);
  }
  iVar1 = param_1[7];
  iVar4 = param_1[6];
  iVar3 = 0;
  if (iVar4 < iVar1) {
    pfVar5 = (float *)(param_1 + 0x202);
    do {
      local_18 = FUN_004969b0(iVar4,0);
      local_14 = FUN_004969b0(iVar4,1);
      local_10 = FUN_004969b0(iVar4,2);
      cVar2 = FUN_00495ed0(local_c,local_8,local_4,&local_18);
      if ((cVar2 == '\x01') && (0.4 < *pfVar5)) {
        *param_5 = iVar4;
        *param_6 = 2;
        *param_7 = iVar3;
        FUN_004afce0(s_Found_extra_plane___d__d_004fb104,*param_5,iVar3);
        return;
      }
      iVar4 = iVar4 + 3;
      iVar3 = iVar3 + 1;
      pfVar5 = pfVar5 + 3;
    } while (iVar4 < iVar1);
  }
  *param_5 = -1;
  *param_6 = 0xffffffff;
  *param_7 = -1;
  return;
}

