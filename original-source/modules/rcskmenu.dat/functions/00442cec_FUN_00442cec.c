/*
 * FUN_00442cec at 00442cec
 * undefined __register FUN_00442cec(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00442cec-00442d26
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442cec(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  
  cVar1 = FUN_00403088(param_1,param_2,param_3);
  FUN_00442c8c(param_1);
  FUN_00442e24(param_1);
  if ((cVar1 != '\0') && (param_1[0x53] != 0)) {
    SetFocus((HWND)param_1[0x53]);
  }
  return;
}

