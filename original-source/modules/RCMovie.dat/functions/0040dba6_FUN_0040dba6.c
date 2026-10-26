/*
 * FUN_0040dba6 at 0040dba6
 * uint __cdecl FUN_0040dba6(int * param_1, int param_2)
 * Address ranges: 0040dba6-0040dc67
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __cdecl FUN_0040dba6(int *param_1,int param_2)

{
  int iVar1;
  uint local_7c;
  COLORREF local_74;
  undefined4 local_70 [9];
  uint *local_4c;
  undefined4 local_1c;
  
  local_7c = 0xffffffff;
  FUN_004028c2(param_1);
  if (param_2 != -1) {
    local_74 = FUN_0040db2b(param_1,0,0);
  }
  _memset(local_70,0,0x6c);
  local_70[0] = 0x6c;
  do {
    iVar1 = (**(code **)(*param_1 + 100))(param_1,0,local_70,0,0);
  } while (iVar1 == -0x7789fde4);
  if (iVar1 == 0) {
    local_7c = *local_4c & (1 << ((byte)local_1c & 0x1f)) - 1U;
    (**(code **)(*param_1 + 0x80))(param_1,0);
  }
  if (param_2 != -1) {
    FUN_0040da05(param_1,0,0,local_74);
  }
  return local_7c;
}

