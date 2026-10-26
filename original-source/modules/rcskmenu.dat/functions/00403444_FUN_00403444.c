/*
 * FUN_00403444 at 00403444
 * undefined4 __register FUN_00403444(void)
 * Address ranges: 00403444-004035a2;004035c3-004035c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00403444(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  bool bVar11;
  PEXCEPTION_RECORD in_stack_00000004;
  PVOID in_stack_00000008;
  ULONG_PTR in_stack_0000000c;
  int *piStack_24;
  
  if ((in_stack_00000004->ExceptionFlags & 6) == 0) {
    if (in_stack_00000004->ExceptionCode == 0xeedfade) {
      iVar3 = *(int *)in_stack_00000004->ExceptionInformation[1];
    }
    else {
      FUN_00402de8();
      if (DAT_0047d008 == (code *)0x0) {
        return 1;
      }
      iVar3 = (*DAT_0047d008)();
      if (iVar3 == 0) {
        return 1;
      }
    }
    iVar8 = *(int *)(*(int *)((int)in_stack_00000008 + 4) + 5);
    piVar9 = (int *)(*(int *)((int)in_stack_00000008 + 4) + 9);
    do {
      piVar4 = (int *)*piVar9;
      iVar10 = iVar3;
      if (piVar4 == (int *)0x0) {
LAB_004034dd:
        if (in_stack_00000004->ExceptionCode == 0xeedfade) {
          if ((DAT_0047b00c < 2) || (DAT_0047b008 != '\0')) goto LAB_00403557;
          piStack_24 = (int *)0x40354f;
          iVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&stack0xfffffff4);
        }
        else {
          uVar5 = (*DAT_0047d00c)();
          FUN_00403238(uVar5,in_stack_0000000c);
          if ((DAT_0047b00c == 0) || (DAT_0047b008 != '\0')) goto LAB_00403557;
          iVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&stack0xfffffff4);
        }
        if (iVar3 == 0) {
          return 1;
        }
LAB_00403557:
        in_stack_00000004->ExceptionFlags = in_stack_00000004->ExceptionFlags | 2;
        piStack_24 = piVar9;
        RtlUnwind(in_stack_00000008,(PVOID)0x403577,in_stack_00000004,(PVOID)0x0);
        piVar9 = piStack_24;
        piStack_24 = (int *)0x403581;
        puVar6 = FUN_00406144();
        piStack_24 = (int *)*puVar6;
        *puVar6 = &piStack_24;
        *(undefined1 **)((int)in_stack_00000008 + 4) = &LAB_004035a3;
        FUN_0040326c();
                    /* WARNING: Could not recover jumptable at 0x004035a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar5 = (*(code *)piVar9[1])();
        return uVar5;
      }
      while( true ) {
        iVar2 = *piVar4;
        if (iVar2 == iVar10) goto LAB_004034dd;
        if (*(int *)(iVar2 + -0x28) == *(int *)(iVar10 + -0x28)) {
          bVar1 = **(byte **)(iVar2 + -0x2c);
          if (bVar1 == **(byte **)(iVar10 + -0x2c)) {
            pbVar7 = *(byte **)(iVar10 + -0x2c) + 1;
            bVar11 = pbVar7 == (byte *)0x0;
            FUN_00402ae4((int *)(*(byte **)(iVar2 + -0x2c) + 1),(int *)pbVar7,(uint)bVar1);
            if (bVar11) goto LAB_004034dd;
          }
        }
        piVar4 = (int *)*piVar9;
        if (*(int **)(iVar10 + -0x24) == (int *)0x0) break;
        iVar10 = **(int **)(iVar10 + -0x24);
      }
      piVar9 = piVar9 + 2;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  return 1;
}

