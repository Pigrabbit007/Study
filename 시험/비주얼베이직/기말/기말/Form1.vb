Public Class Form1
    Private strname As String
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        With OpenFileDialog1
            .Filter = "텍스트 파일 (*.txt)|*.txt|모든 파일 (*.*)|*.*"
            .FilterIndex = 1
            .FileName = ""
            .Title = "불러오기"
        End With

        If OpenFileDialog1.ShowDialog = Windows.Forms.DialogResult.OK Then
            Try
                strname = OpenFileDialog1.FileName
                Dim filecontent As String
                filecontent = My.Computer.FileSystem.ReadAllText(strname)
                TextBox1.Text = filecontent
            Catch ex As Exception
                MessageBox.Show(ex.Message, My.Application.Info.Title, MessageBoxButtons.OK, MessageBoxIcon.Error)
            End Try
        End If
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        With SaveFileDialog1
            .Filter = "텍스트 파일 (*.txt)|*.txt|모든 파일 (*.*)|*.*"
            .FilterIndex = 1
            .FileName = strname
            .DefaultExt = "txt"
            .OverwritePrompt = True
            .Title = "저장"
        End With
        If SaveFileDialog1.ShowDialog = Windows.Forms.DialogResult.OK Then
            Try
                strname = SaveFileDialog1.FileName
                My.Computer.FileSystem.WriteAllText(strname, TextBox1.Text, False)
            Catch ex As Exception
                MessageBox.Show(ex.Message, My.Application.Info.Title, MessageBoxButtons.OK, MessageBoxIcon.Error)
            End Try
        End If
    End Sub
End Class
