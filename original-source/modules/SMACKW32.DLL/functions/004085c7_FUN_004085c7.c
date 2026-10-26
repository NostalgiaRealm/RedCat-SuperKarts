/*
 * FUN_004085c7 at 004085c7
 * undefined8 __fastcall FUN_004085c7(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004085c7-0040863f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_004085c7(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  (*(code *)PTR_FUN_0040ef78)();
  iVar2 = 0;
  iVar1 = 0;
  while( true ) {
    if (DAT_004104f4 * 4 <= iVar1) {
      DAT_004104f8 = FUN_00408ff5(DAT_004104f4 * 4,(DAT_004104f4 + 1) * 4);
      DAT_004104f8[DAT_004104f4] = in_EAX;
      DAT_004104f4 = DAT_004104f4 + 1;
      (*(code *)PTR_FUN_0040ef7c)();
      return CONCAT44(param_2,DAT_004104f4 + -1);
    }
    if (*(int *)((int)DAT_004104f8 + iVar1) == 0) break;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + 1;
  }
  *(int *)((int)DAT_004104f8 + iVar1) = in_EAX;
  (*(code *)PTR_FUN_0040ef7c)();
  return CONCAT44(param_2,iVar2);
}

