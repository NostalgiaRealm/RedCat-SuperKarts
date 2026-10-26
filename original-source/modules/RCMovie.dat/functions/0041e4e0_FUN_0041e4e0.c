/*
 * FUN_0041e4e0 at 0041e4e0
 * undefined4 __cdecl FUN_0041e4e0(int param_1, undefined4 param_2)
 * Address ranges: 0041e4e0-0041e67a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0041e4e0(int param_1,undefined4 param_2)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  char in_stack_0000001c;
  undefined4 uStack_a4;
  undefined1 *local_80 [2];
  int local_78 [27];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00427ef8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0041efe0(local_78);
  uVar6 = 0;
  local_4 = 0;
  FUN_0041f090((int)local_78);
  uStack_a4 = 0x41e52d;
  FUN_0041e440(param_2);
  FUN_0041ee10(local_78,param_2);
  FUN_0041f060(local_78,param_1);
  uVar3 = FUN_0041e900((int *)&stack0x0000000c);
  if ((char)uVar3 != '\0') {
    iVar4 = FUN_0041efb0((int)local_78);
    puVar5 = (undefined4 *)FUN_0041e8d0(iVar4);
    FUN_0041e8b0(&stack0x0000000c,puVar5);
  }
  local_80[0] = (undefined1 *)&uStack_a4;
  FUN_0041e870(&uStack_a4,(undefined4 *)&stack0x0000000c);
  FUN_0041f070((int)local_78);
  FUN_0041f050(local_78);
  FUN_0041eec0((int)local_78);
  bVar1 = false;
LAB_0041e5b2:
  while( true ) {
    if (DAT_0043d534 == 0) {
      FUN_0041ef10((int)local_78);
      while (DAT_0043d534 == 0) {
        FUN_0040a97d();
      }
      FUN_0041eec0((int)local_78);
    }
    iVar4 = FUN_0041e680();
    if (iVar4 == 1) break;
    if (iVar4 == 2) {
      if (bVar1) {
        bVar1 = false;
        FUN_0041eec0((int)local_78);
      }
      goto LAB_0041e61a;
    }
    if ((iVar4 != 3) || (bVar1)) goto LAB_0041e615;
    bVar1 = true;
    FUN_0041ef10((int)local_78);
  }
  uVar6 = 0xfffffffe;
LAB_0041e64d:
  local_4 = 0xffffffff;
  FUN_0041e980(local_78);
  ExceptionList = pvStack_c;
  return uVar6;
LAB_0041e615:
  if (!bVar1) {
LAB_0041e61a:
    cVar2 = FUN_0041ee30(local_78);
    if (cVar2 == '\0') {
      if (in_stack_0000001c == '\0') goto LAB_0041e64d;
      FUN_0041efc0(local_80,0);
      FUN_0041ef60(local_78,(undefined8 *)local_80);
    }
  }
  goto LAB_0041e5b2;
}

