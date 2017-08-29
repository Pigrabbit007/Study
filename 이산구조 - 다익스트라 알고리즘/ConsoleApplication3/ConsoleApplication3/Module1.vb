Module Module1

    Sub Main()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(j) = Convert.ToString(j)
            Next

            For j = 1 To i
                Console.Write("{0}", a(j))
            Next

            Console.WriteLine()

        Next
        Console.WriteLine()
        IT()
        y()
        x()
        z()
        a1()
        a2()
        a4()
        a3()
        a5()
        a6()
        a7()
        a8()
        a9()
        a10()
        a11()

    End Sub

    Sub IT()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(j) = Convert.ToString(j)
            Next

            For j = i To j
                Console.Write("{0}", a(j))
            Next

            Console.WriteLine()

        Next
        Console.WriteLine()
    End Sub

    Sub x()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(10 - j) = Convert.ToString(j)
            Next

            For j = i To 9
                Console.Write("")
            Next

            For j = i To 9
                Console.Write("{0}", a(j))
            Next

            Console.WriteLine()

        Next

        Console.WriteLine()

    End Sub

    Sub y()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(10 - j) = Convert.ToString(j)
            Next

            For j = i To 9
                Console.Write("")
            Next

            For j = 1 To i
                Console.Write("{0}", a(j))
            Next

            Console.WriteLine()

        Next

        Console.WriteLine()

    End Sub
    Sub z()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(j) = Space(1)
            Next

            For j = 1 To 9
                a(i) = Convert.ToString(i)
                a(10 - i) = Convert.ToString(10 - i)
            Next

            a(5) = Convert.ToString(5)

            For j = 1 To 9
                Console.Write("{0}", a(j))
            Next

            Console.WriteLine()

        Next
        Console.WriteLine()
    End Sub
    Sub a1()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(j) = Space(1)
            Next j

            For j = 1 To 9
                a(i) = Convert.ToString(i)
                a(10 - i) = Convert.ToString(10 - i)
            Next j

            a(5) = Convert.ToString(5)

            For j = 1 To 9
                If (i = 5) Then
                    Console.Write("5")
                Else
                    Console.Write("{0}", a(j))
                End If

            Next j

            Console.WriteLine()

        Next i
        Console.WriteLine()
    End Sub
    Sub a2()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(j) = Space(1)
            Next

            For j = 1 To 9
                a(i) = Convert.ToString(i)
                a(10 - i) = Convert.ToString(10 - i)
            Next

            For j = 1 To 9
                Console.Write("{0}", a(j))
            Next

            Console.WriteLine()

        Next
        Console.WriteLine()
    End Sub
    Sub a3()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(j) = Convert.ToString(j)
            Next
            For j = 2 To i
                Console.Write(" ")
            Next
            For j = i To 9
                Console.Write("{0} ", a(j))
            Next

            Console.WriteLine()

        Next
        Console.WriteLine()
    End Sub
    Sub a4()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(j) = Convert.ToString(j)
            Next
            For j = i To 8
                Console.Write(" ")
            Next
            For j = 1 To i
                Console.Write("{0} ", a(j))
            Next

            Console.WriteLine()

        Next
        Console.WriteLine()
    End Sub
    Sub a5()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(10 - j) = Convert.ToString(j)
            Next
            For j = i To 8
                Console.Write(" ")
            Next
            For j = 1 To i
                Console.Write("{0} ", a(j))
            Next

            Console.WriteLine()

        Next
        Console.WriteLine()
    End Sub
    Sub a6()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(10 - j) = Convert.ToString(j)
            Next
            For j = 2 To i
                Console.Write(" ")
            Next
            For j = i To 9
                Console.Write("{0} ", a(j))
            Next

            Console.WriteLine()

        Next
        Console.WriteLine()
    End Sub
    Sub a7()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(j) = Convert.ToString(j)
            Next

            For j = 2 To i
                Console.Write(" ")
            Next

            For j = i To 9
                Console.Write("{0}", a(j))
            Next

            Console.WriteLine()

        Next
        Console.WriteLine()
    End Sub
    Sub a8()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(j) = Convert.ToString(j)
            Next

            For j = i To 8
                Console.Write(" ")
            Next

            For j = 1 To i
                Console.Write("{0}", a(j))
            Next

            Console.WriteLine()

        Next
        Console.WriteLine()
    End Sub
    Sub a9()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(j) = Convert.ToString(j)
            Next

            For j = 2 To i
                Console.Write(" ")
            Next

            For j = i To i
                Console.Write("{0}", a(j))
            Next

            Console.WriteLine()

        Next
        Console.WriteLine()
    End Sub
    Sub a10()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(j) = Convert.ToString(j)
            Next

            For j = i To 8
                Console.Write(" ")
            Next

            For j = i To i
                Console.Write("{0}", a(j))
            Next

            Console.WriteLine()

        Next
        Console.WriteLine()
    End Sub
    Sub a11()
        Dim a(10) As String
        Dim i, j As Integer

        For i = 1 To 9
            For j = 1 To 9
                a(j) = Space(1)
            Next

            For j = i To 9
                a(i) = Convert.ToString(i)
                a(10 - i) = Convert.ToString(10 - i)
            Next

            a(5) = Convert.ToString(5)

            For j = 1 To 9
                If (i = 5) Then
                    Console.Write("5")
                Else
                    Console.Write("{0}", a(j))
                End If
            Next

            Console.WriteLine()

        Next
        Console.WriteLine()
    End Sub
End Module