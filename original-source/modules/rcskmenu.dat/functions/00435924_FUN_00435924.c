/*
 * FUN_00435924 at 00435924
 * undefined __register FUN_00435924(undefined2 param_1, int * param_2)
 * Address ranges: 00435924-00435977
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00435924(undefined2 param_1,int *param_2)

{
  UINT UVar1;
  CHAR local_106 [256];
  undefined2 local_6;
  
  local_6 = param_1;
  FUN_00403b50(param_2);
  UVar1 = MapVirtualKeyA((uint)(byte)local_6,0);
  if (UVar1 << 0x10 != 0) {
    GetKeyNameTextA(UVar1 << 0x10,local_106,0x100);
    FUN_00403d80(param_2,local_106,0x100);
  }
  return;
}

