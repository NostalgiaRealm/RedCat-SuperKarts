/*
 * FUN_00403768 at 00403768
 * undefined FUN_00403768(void)
 * Address ranges: 00403768-00403803
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00403768(void)

{
  DWORD DVar1;
  LONG LVar2;
  PEXCEPTION_RECORD pEVar3;
  ULONG_PTR UVar4;
  undefined4 uVar5;
  PVOID pvVar6;
  PEXCEPTION_RECORD in_stack_00000004;
  PCONTEXT in_stack_00000008;
  
  if (((in_stack_00000004->ExceptionFlags & 6) != 0) ||
     ((DAT_0047b008 == '\0' &&
      (LVar2 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&stack0x00000004), LVar2 == 0)))) {
    return 0;
  }
  pEVar3 = (PEXCEPTION_RECORD)FUN_00402de8();
  RtlUnwind(in_stack_00000008,(PVOID)0x4037ad,pEVar3,(PVOID)0x0);
  pEVar3 = in_stack_00000004;
  pvVar6 = (PVOID)in_stack_00000004->ExceptionInformation[0];
  UVar4 = in_stack_00000004->ExceptionInformation[1];
  if (in_stack_00000004->ExceptionCode == 0xeedfade) {
LAB_004037dc:
    FUN_004032f8(UVar4,(ULONG_PTR)pvVar6);
    if (DAT_0047d000 != (code *)0x0) {
      (*DAT_0047d000)();
    }
    uVar5 = FUN_00403b28(0xd9);
    return uVar5;
  }
  if ((DAT_0047d00c != (code *)0x0) && (UVar4 = (*DAT_0047d00c)(in_stack_00000004), UVar4 != 0)) {
    pvVar6 = pEVar3->ExceptionAddress;
    goto LAB_004037dc;
  }
  DVar1 = in_stack_00000004->ExceptionCode;
  if ((int)DVar1 < -0x3fffff6d) {
    if (DVar1 == 0xc0000092) {
LAB_00403735:
      uVar5 = 0xcf;
      goto LAB_00403757;
    }
    if ((int)DVar1 < -0x3fffff71) {
      if (DVar1 == 0xc000008e) {
        uVar5 = 200;
        goto LAB_00403757;
      }
      if (DVar1 == 0xc0000005) {
        uVar5 = 0xd8;
        goto LAB_00403757;
      }
      if (DVar1 == 0xc000008c) {
        uVar5 = 0xc9;
        goto LAB_00403757;
      }
      if (DVar1 == 0xc000008d) goto LAB_00403741;
    }
    else {
      if (DVar1 + 0x3fffff71 < 2) goto LAB_00403735;
      if (DVar1 + 0x3fffff71 == 2) {
        uVar5 = 0xcd;
        goto LAB_00403757;
      }
    }
  }
  else if ((int)DVar1 < -0x3fffff69) {
    if (DVar1 == 0xc0000096) {
      uVar5 = 0xda;
      goto LAB_00403757;
    }
    if (DVar1 == 0xc0000093) {
LAB_00403741:
      uVar5 = 0xce;
      goto LAB_00403757;
    }
    if (DVar1 == 0xc0000094) {
      uVar5 = 200;
      goto LAB_00403757;
    }
    if (DVar1 == 0xc0000095) {
      uVar5 = 0xd7;
      goto LAB_00403757;
    }
  }
  else {
    if (DVar1 == 0xc00000fd) {
      uVar5 = 0xca;
      goto LAB_00403757;
    }
    if (DVar1 == 0xc000013a) {
      uVar5 = 0xd9;
      goto LAB_00403757;
    }
  }
  uVar5 = 0xff;
LAB_00403757:
  uVar5 = FUN_004036bc(uVar5);
  return uVar5;
}

