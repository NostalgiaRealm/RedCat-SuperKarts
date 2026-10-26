/*
 * FUN_00403318 at 00403318
 * undefined4 __register FUN_00403318(void)
 * Address ranges: 00403318-0040341a;0040343b-00403440
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00403318(void)

{
  DWORD DVar1;
  int iVar2;
  LONG LVar3;
  PEXCEPTION_RECORD pEVar4;
  LPVOID pvVar5;
  undefined4 uVar6;
  PEXCEPTION_RECORD in_stack_00000004;
  PCONTEXT in_stack_00000008;
  ULONG_PTR in_stack_0000000c;
  
  if ((in_stack_00000004->ExceptionFlags & 6) == 0) {
    pEVar4 = in_stack_00000004;
    if (in_stack_00000004->ExceptionCode != 0xeedfade) {
      FUN_00402de8();
      if (DAT_0047d00c == (code *)0x0) {
        return 1;
      }
      iVar2 = (*DAT_0047d00c)();
      if (iVar2 == 0) {
        return 1;
      }
      pEVar4 = in_stack_00000004;
      if (((in_stack_00000004->ExceptionCode != 0xeefface) &&
          (FUN_00403238(iVar2,in_stack_0000000c), pEVar4 = in_stack_00000004, DAT_0047b00c != 0)) &&
         (DAT_0047b008 == '\0')) {
        LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&stack0x00000004);
        if (LVar3 == 0) {
          return 1;
        }
        goto LAB_004033cc;
      }
    }
    in_stack_00000004 = pEVar4;
    if (((DAT_0047b00c < 2) || (DAT_0047b008 != '\0')) ||
       (LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&stack0x00000004), LVar3 != 0)) {
LAB_004033cc:
      in_stack_00000004->ExceptionFlags = in_stack_00000004->ExceptionFlags | 2;
      RtlUnwind(in_stack_00000008,(PVOID)0x4033ef,in_stack_00000004,(PVOID)0x0);
      pvVar5 = FUN_00406144();
      *(undefined1 **)pvVar5 = &stack0xffffffdc;
      DVar1 = in_stack_00000008->Dr0;
      in_stack_00000008->Dr0 = (DWORD)&LAB_0040341b;
      FUN_00403280();
                    /* WARNING: Could not recover jumptable at 0x00403419. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar6 = (*(code *)(DVar1 + 5))();
      return uVar6;
    }
  }
  return 1;
}

