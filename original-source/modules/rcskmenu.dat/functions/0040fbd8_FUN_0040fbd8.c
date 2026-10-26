/*
 * FUN_0040fbd8 at 0040fbd8
 * undefined __register FUN_0040fbd8(int param_1, uint param_2, char param_3)
 * Address ranges: 0040fbd8-0040fc02
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040fbd8(int param_1,uint param_2,char param_3)

{
  byte *pbVar1;
  int *piVar2;
  
  if (*(uint *)(param_1 + 4) <= param_2) {
    if ((int)param_2 < 0) {
      piVar2 = FUN_0040ad20((int *)&DAT_0040dc9c,'\x01',(undefined4 *)PTR_PTR_0047c930);
      FUN_00403604(piVar2);
      return;
    }
    FUN_0040fb34(param_1,param_2 + 1);
  }
  if (param_3 != '\0') {
    pbVar1 = (byte *)(*(int *)(param_1 + 8) + ((int)param_2 >> 3));
    *pbVar1 = *pbVar1 | '\x01' << (param_2 & 7);
    return;
  }
  pbVar1 = (byte *)(*(int *)(param_1 + 8) + ((int)param_2 >> 3));
  *pbVar1 = *pbVar1 & ~('\x01' << (param_2 & 7));
  return;
}

