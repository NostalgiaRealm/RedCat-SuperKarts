/*
 * FUN_0045bbb4 at 0045bbb4
 * undefined __register FUN_0045bbb4(undefined4 * param_1, int * param_2)
 * Address ranges: 0045bbb4-0045bc81
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045bbb4(undefined4 *param_1,int *param_2)

{
  undefined4 local_60;
  undefined1 local_5c;
  uint local_58;
  undefined1 local_54;
  uint local_50;
  undefined1 local_4c;
  uint local_48;
  undefined1 local_44;
  uint local_40;
  undefined1 local_3c;
  uint local_38;
  undefined1 local_34;
  uint local_30;
  undefined1 local_2c;
  uint local_28;
  undefined1 local_24;
  uint local_20;
  undefined1 local_1c;
  uint local_18;
  undefined1 local_14;
  uint local_10;
  undefined1 local_c;
  
  if (param_1 == (undefined4 *)0x0) {
    FUN_00403ba4(param_2,(undefined4 *)"0,0,0,0,0,0,0,0,0,0,0");
  }
  else {
    local_60 = *param_1;
    local_5c = 0;
    local_58 = (uint)*(ushort *)(param_1 + 1);
    local_54 = 0;
    local_50 = (uint)*(ushort *)((int)param_1 + 6);
    local_4c = 0;
    local_48 = (uint)*(byte *)(param_1 + 2);
    local_44 = 0;
    local_40 = (uint)*(byte *)((int)param_1 + 9);
    local_3c = 0;
    local_38 = (uint)*(byte *)((int)param_1 + 10);
    local_34 = 0;
    local_30 = (uint)*(byte *)((int)param_1 + 0xb);
    local_2c = 0;
    local_28 = (uint)*(byte *)(param_1 + 3);
    local_24 = 0;
    local_20 = (uint)*(byte *)((int)param_1 + 0xd);
    local_1c = 0;
    local_18 = (uint)*(byte *)((int)param_1 + 0xe);
    local_14 = 0;
    local_10 = (uint)*(byte *)((int)param_1 + 0xf);
    local_c = 0;
    FUN_00408a5c((byte *)"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&local_60,10,param_2);
  }
  return;
}

